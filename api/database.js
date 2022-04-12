const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'netuser',
  password: 'salasana',
  database: 'pankkimaatti'
});
module.exports = connection;