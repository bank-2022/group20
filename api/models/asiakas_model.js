const db = require('../database');

const asiakas = {
  getById: function(id, callback) {
    return db.query('select * from asiakas where id_asiakas=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  add: function(asiakas, callback) {
    return db.query(
      'insert into asiakas (Fname,Lahiosoite,Puhelinnumero,Pin) values(?,?,?,?)',
      [asiakas.Fname, asiakas.Lahiosoite, asiakas.Puhelinnumero, asiakas.Pin],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas where id_asiakas=?', [id], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set Fname=?,Lahiosoite=?, Puhelinnumero=?, Pin=? where id_asiakas=?',
      [asiakas.Fname, asiakas.Lahiosoite, asiakas.Puhelinnumero, asiakas.Pin, id],
      callback
    );
  }
};
module.exports = asiakas;