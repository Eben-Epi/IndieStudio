#!/bin/bash

DIR_PATH=`dirname "$0"`
ECS_PATH="$DIR_PATH/src/ecs/Systems/"
FILE_PATH="$ECS_PATH/$1System.hpp"

echo $ECS_PATH

if read -p "Voulez vous vraiment editer le fichier '$FILE_PATH' ?" Y
then
    FILE_HEADER=`head -n 10 $FILE_PATH`
    FILE_FOOTER=`tail -n 3 $FILE_PATH`
    if [ $? -ne 0 ]
    then
	exit 1
    fi
    echo -e "$FILE_HEADER

#include \"../System.hpp\"

namespace ECS {
    class $1 : public System {
        public:
        void updateEntity(Entity &entity) override;
    };
}
$FILE_FOOTER" > $FILE_PATH
fi
