#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "dllist.hpp"

const int MAX_CONSUMABLES_COUNT = 8;
const int NEW_CONSUMABLE_PROB = 1;

void addConsumableNode(List& consumables, const Circle& playerCircle) {
    Circle circle;
    while (true) {
        circle = generateCircle(CONSUMABLE_RADIUS);
        bool collides = collision(circle, playerCircle);
        Node* curr = consumables.sentry.next;
        while (curr && curr != &consumables.sentry && !collides) {
            Node* next = curr->next;
            Circle currentCircle = ((Consumable*) curr->data)->circle;
            collides = collision(circle, currentCircle);
            curr = next;
        }
        if (collides) continue;
        break;
    }
    Consumable* consumable = (Consumable*) malloc(sizeof(Consumable));
    consumable->circle = circle;
    consumable->concerned = false;
    consumable->destroyed = false;
    insert(consumables, consumable);
}

void createConsumablesList(List& list, int count, Circle playerCircle) {
    for (int i = 0; i < count; ++i) {
        addConsumableNode(list, playerCircle);
    }
}

void processEvent(sf::RenderWindow& window, const sf::Event& event) {
    switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
    }
}

void processInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        processEvent(window, event);
    }
}

bool destroyedConsumable(void* data) {
    return ((Consumable*) data)->destroyed;
}

void update(sf::Time delta, sf::CircleShape& player, List& consumables) {
    Point2D playerPosition = { player.getPosition().x, player.getPosition().y };
    Point2D playerVelocity = calculateVelocity();
    Point2D newPlayerPosition = move(playerPosition, playerVelocity, 0.001f * delta.asMilliseconds());
    Point2D adjustedPlayerPosition = adjustToBorders(newPlayerPosition);
    player.setPosition(adjustedPlayerPosition.x, adjustedPlayerPosition.y);

    Circle playerCircle = { playerPosition, RADIUS };

    Node* curr = consumables.sentry.next;
    int count = 0;
    while (curr && curr != &consumables.sentry) {
        Node* next = curr->next;
        auto* consumable = (Consumable*) curr->data;
        float dist = distance(playerCircle.center, consumable->circle.center);
        float warnDist = 3 * playerCircle.radius + consumable->circle.radius;
        float collisionDist = playerCircle.radius + consumable->circle.radius;
        consumable->concerned = (dist < warnDist);
        consumable->destroyed = (dist < collisionDist);
        curr = next;
        count++;
    }
    if (count < MAX_CONSUMABLES_COUNT) {
        int r = rand() % 100;
        if (r < NEW_CONSUMABLE_PROB) {
            addConsumableNode(consumables, playerCircle);
        }
    }
    remove(consumables, destroyedConsumable);
}

void render(sf::RenderWindow& window, sf::Sprite& background, const sf::CircleShape& player, const List& consumables,
            const sf::Texture& consumableTexture, const sf::Texture& concernedTexture) {
    window.clear(sf::Color::White);
    window.draw(background);
    window.draw(player);
    Node* curr = consumables.sentry.next;
    while (curr && curr != &consumables.sentry) {
        auto* consumable = (Consumable*) curr->data;
        const auto& texture = consumable->concerned ? concernedTexture : consumableTexture;
        sf::CircleShape shape;
        initConsumable(shape, consumable->circle, texture);
        window.draw(shape);
        curr = curr->next;
    }
    window.display();
}

int main() {
    int status = 0;

    srand(time(NULL));

    sf::RenderWindow window;
    status = initWindow(window);
    if (status != 0) {
        return status;
    }

    sf::Sprite background;
    sf::Texture backgroundTexture;
    status = initBackrground(background, backgroundTexture);
    if (status != 0) {
        return status;
    }

    sf::CircleShape player;
    sf::Texture playerTexture;
    status = initPlayer(player, playerTexture);
    if (status != 0) {
        return status;
    }
    Circle playerCircle = { {player.getPosition().x, player.getPosition().y}, player.getRadius() };

    sf::Texture consumableTexture;
    status = initConsumableTexture(consumableTexture);
    if (status != 0) {
        return status;
    }

    sf::Texture concernedTexture;
    std::string filename = "resources/starConcerned.png";
    if (!concernedTexture.loadFromFile(filename)) {
        return 1;
    }

    const int INIT_COUNT = 4;
    List consumables = { { nullptr, nullptr, nullptr } };
    initList(consumables);
    createConsumablesList(consumables, INIT_COUNT, playerCircle);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time delta = clock.restart();
        processInput(window);
        update(delta, player, consumables);
        render(window, background, player, consumables, consumableTexture, concernedTexture);
    }

    freeList(consumables);
}