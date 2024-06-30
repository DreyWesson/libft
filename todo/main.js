import './style.css'
import { Todo } from './todo.class.js';
import { handleApp } from './todo.func.js';
import { ui } from './ui.js';


const app = document.querySelector('#app');

app.innerHTML = ui;

handleApp(app);
document.addEventListener("DOMContentLoaded", () => { new Todo(app) })
// const a =;
