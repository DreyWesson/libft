/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:42:05 by doduwole          #+#    #+#             */
/*   Updated: 2023/12/09 19:27:19 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

void debug_logic() {
    Character character("Alice");
    Ice iceMateria;
    Cure cureMateria;

    // Equip Materia to the character
    character.equip(&iceMateria);
    character.equip(&cureMateria);

    // Use Materias
    character.use(0, character); // Use Ice Materia
    character.use(1, character); // Use Cure Materia

    character.unequip(0); // Unequip a Materia

    // 
    character.use(0, character); //Attempt to use the unequipped Materia Should do nothing

    Character bob("Bob");
    Character eve("Eve");

    bob.equip(&iceMateria);
    eve.equip(&cureMateria);

    // Use Materias with different characters
    bob.use(0, eve);
    eve.use(0, bob);

    // Unequip and use unequipped Materia
    bob.unequip(0);
    bob.use(0, eve); // Should do nothing
}
void subject_test() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
}

int main()
{
    subject_test();
    // debug_logic();
    return 0;
}