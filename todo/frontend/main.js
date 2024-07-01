import './style.css'
// import { Todo } from './todo.class.js';
import { Todo } from './todo.func.js';
import { ui } from './ui.js';



const app = document.querySelector('#app');
document.addEventListener("DOMContentLoaded", () => {
    app.innerHTML = ui;
    // new Todo(app)
    Todo(app);
})
