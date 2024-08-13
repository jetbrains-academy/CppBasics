#ifndef CPPBASICS_TESTSCENE_HPP
#define CPPBASICS_TESTSCENE_HPP

#include <utility>

#include "scene.hpp"
#include "gobject.hpp"
#include "cgobject.hpp"
#include "player.hpp"
#include "consumable.hpp"
#include "enemy.hpp"
#include "constants.hpp"
#include "dynscene.hpp"
#include "leaderboard.hpp"
#include "leaderboardscene.hpp"

class TestGameObject : public GameObject {
public:

    inline TestGameObject()
        : position(Point2D { 0.0f, 0.0f })
        , velocity(Point2D { 0.0f, 0.0f })
        , status(GameObjectStatus::NORMAL)
        , kind(GameObjectKind::CONSUMABLE)
    {}

    inline TestGameObject(Point2D position, Point2D velocity, GameObjectStatus status, GameObjectKind kind)
        : position(position)
        , velocity(velocity)
        , status(status)
        , kind(kind)
    {}

    TestGameObject(const TestGameObject& other) = default;
    TestGameObject& operator=(const TestGameObject& other) = default;

    inline Point2D getPosition() const override {
        return position;
    }

    inline void setPosition(Point2D position) override {
        this->position = position;
    }

    inline GameObjectStatus getStatus() const override {
        return status;
    }

    inline void setStatus(GameObjectStatus status) {
        this->status = status;
    }

    inline GameObjectKind getKind() const override {
        return kind;
    }

    inline void setKind(GameObjectKind kind) {
        this->kind = kind;
    }

    inline Point2D getVelocity() const override {
        return velocity;
    }

    inline Rectangle getBoundingBox() const override {
        return Rectangle { position, position };
    }

    inline void update(sf::Time delta) override {
        return;
    }

    inline void onCollision(const GameObject& object, const CollisionInfo& info) override {
        return;
    }

    inline void draw(sf::RenderWindow& window, TextureManager& textureManager) const override {
        return;
    }

    inline const sf::Texture* getTexture(TextureManager& textureManager) const override {
        return nullptr;
    }

    void performMove(Point2D vector) {
        move(vector);
    }

private:
    Point2D position;
    Point2D velocity;
    GameObjectStatus status;
    GameObjectKind kind;
};

class TestCircleGameObject : public CircleGameObject {
public:

    inline TestCircleGameObject()
        : CircleGameObject(Circle { Point2D { CONSUMABLE_START_X, CONSUMABLE_START_Y }, CONSUMABLE_RADIUS })
        , velocity(Point2D { 0.0f, 0.0f })
        , kind(GameObjectKind::CONSUMABLE)
    {}

    inline TestCircleGameObject(Circle circle, Point2D velocity, GameObjectKind kind)
        : CircleGameObject(circle)
        , velocity(velocity)
        , kind(kind)
    {}

    TestCircleGameObject(const TestCircleGameObject& other) = default;
    TestCircleGameObject& operator=(const TestCircleGameObject& other) = default;

    inline GameObjectKind getKind() const override {
        return kind;
    }

    inline Point2D getVelocity() const override {
        return velocity;
    }

    inline void update(sf::Time delta) override {
        return;
    }

    inline void onCollision(const GameObject& object, const CollisionInfo& info) override {
        return;
    }

    inline const sf::Texture* getTexture(TextureManager& textureManager) const override {
        return nullptr;
    }

    void performSetStatus(GameObjectStatus status) {
        setStatus(status);
    }

    void performSetPosition(Point2D position) {
        setPosition(position);
    }

private:
    Point2D velocity;
    GameObjectKind kind;
};

class TestPlayerObject : public PlayerObject {
public:

    inline TestPlayerObject() : PlayerObject() {}

    TestPlayerObject(const TestPlayerObject& other) = default;
    TestPlayerObject& operator=(const TestPlayerObject& other) = default;

    inline void performSetStatus(GameObjectStatus status) {
        setStatus(status);
    }

    inline void performSetPosition(Point2D position) {
        setPosition(position);
    }
};

class TestConsumableObject : public ConsumableObject {
public:

    inline TestConsumableObject() : ConsumableObject() {}

    TestConsumableObject(const TestConsumableObject& other) = default;
    TestConsumableObject& operator=(const TestConsumableObject& other) = default;

    inline void performSetStatus(GameObjectStatus status) {
        setStatus(status);
    }

    inline void performSetPosition(Point2D position) {
        setPosition(position);
    }
};

class TestEnemyObject : public EnemyObject {
public:

    inline TestEnemyObject() : EnemyObject() {}

    TestEnemyObject(const TestEnemyObject& other) = default;
    TestEnemyObject& operator=(const TestEnemyObject& other) = default;

    inline void performSetStatus(GameObjectStatus status) {
        setStatus(status);
    }

    inline void performSetPosition(Point2D position) {
        setPosition(position);
    }

    inline void performSetVelocity(Point2D velocity) {
        setVelocity(velocity);
    }

    inline void performUpdateVelocity() {
        updateVelocity();
    }
};

class TestScene : public Scene {
public:
    GameObjectList objects;

    inline TestScene(float width, float height) : Scene(width, height) {}

    inline void activate() override {}
    inline void deactivate() override {}

    inline SceneID getID() const override {
        return SceneID::DYNAMIC_GAME_FIELD;
    }

    inline SceneID getNextSceneID() const override {
        return SceneID::DYNAMIC_GAME_FIELD;
    }

    inline void processEvent(const sf::Event& event) override {}

    inline void update(sf::Time delta) override {}

    inline void draw(sf::RenderWindow &window, TextureManager& textureManager) override {}

    inline void performSetObjectPosition(GameObject& object, Point2D position) {
        setObjectPosition(object, position);
    }

    inline void performMove(GameObject& object, Point2D vector) {
        move(object, vector);
    }

    inline void insertPlayerObject(TestPlayerObject& object) {
        objects.insert(std::make_shared<TestPlayerObject>(object));
    }
};

class TestGameplayDynamicScene : public GameplayDynamicScene {
public:

    inline TestGameplayDynamicScene() : GameplayDynamicScene() {}

    inline void activate() override {
        GameplayDynamicScene::activate();
    }

    inline void deactivate() override {
        GameplayDynamicScene::deactivate();
    }

    inline SceneID getID() const override {
        return GameplayDynamicScene::getID();
    }

    inline SceneID getNextSceneID() const override {
        return GameplayDynamicScene::getNextSceneID();
    }

    inline void processEvent(const sf::Event& event) override {
        GameplayDynamicScene::processEvent(event);
    }

    inline void update(sf::Time delta) override {
        GameplayDynamicScene::update(delta);
    }

    inline void draw(sf::RenderWindow &window, TextureManager& textureManager) override {
        GameplayDynamicScene::draw(window, textureManager);
    }

    inline void performUpdateObjectsList() {
        updateObjectsList();
    }

    inline std::shared_ptr<GameObject> performAddNewGameObject(GameObjectKind kind) {
        return addNewGameObject(kind);
    }

    inline void performUpdateScore() {
        updateScore();
    }

    inline unsigned int performGetScore() const {
        return getScore();
    }

    inline void insertPlayerObject(TestPlayerObject& object) {
        objects.insert(std::make_shared<TestPlayerObject>(object));
        player = std::make_shared<TestPlayerObject>(object);
    }

    inline void insertEnemyObject(TestEnemyObject& object) {
        objects.insert(std::make_shared<TestEnemyObject>(object));
    }

    std::shared_ptr<PlayerObject> getPlayer() {
        return player;
    }
};

class TestLeaderboard : public Leaderboard {
public:
    std::string testFilepath = "../../../../resources/test.csv";

    inline TestLeaderboard() : Leaderboard() {}

    inline void loadScores() {
        std::ifstream file(testFilepath);
        if (file.is_open()) {
            std::string line;
            while (getline(file, line)) {
                std::stringstream ss(line);
                std::string name;
                unsigned int score;
                getline(ss, name, ',');
                ss >> score;
                this->scores.insert({score, name});
            }
            file.close();
        } else {
            std::cout << "Unable to open file: " << this->testFilepath << std::endl;
        }
    }

    inline void addScore(unsigned int score, std::string name = "Tester") {
        Leaderboard::addScore(score, name);
    }

    inline void saveScores() {
        std::ofstream
            file(testFilepath);
        if (file.is_open()) {
            for (const auto &[score, name]: scores) {
                file << name << "," << score << std::endl;
            }
            file.close();
        } else {
            std::cout << "Unable to open file: " << this->testFilepath << std::endl;
        }
    }

    inline void performUpdateScore(unsigned int score) {
        loadScores();
        addScore(score);
        saveScores();
    }
};

class TestLeaderboardScene : public LeaderboardScene {
public:
    inline TestLeaderboardScene() : LeaderboardScene() {}

    inline void activate() override {
        LeaderboardScene::activate();
    }

    inline void deactivate() override {
        LeaderboardScene::deactivate();
    }

    inline SceneID getID() const override {
        return LeaderboardScene::getID();
    }

    inline SceneID getNextSceneID() const override {
        return LeaderboardScene::getNextSceneID();
    }

    inline void processEvent(const sf::Event& event) override {
        LeaderboardScene::processEvent(event);
    }

    inline void update(sf::Time delta) override {
        LeaderboardScene::update(delta);
    }

    inline void draw(sf::RenderWindow &window, TextureManager& textureManager) override {
        LeaderboardScene::draw(window, textureManager);
    }

    inline std::string getPlayerName() const {
        return playerName;
    }

    inline LeaderboardState getState() const {
        return state;
    }

    inline unsigned int getPlayerScore() const {
        return playerScore;
    }
};

#endif //CPPBASICS_TESTSCENE_HPP
