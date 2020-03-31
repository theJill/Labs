module.exports = (Sequelize, config) => {
    const options = {
        dialect: 'sqlite',
    };
    const sequelize = new Sequelize(config.db.name, config.db.user, config.db.password, options);


    const Model = require('../models/model')(Sequelize, sequelize);

    return {
        model: Model,

        sequelize,
        Sequelize,
    }
};