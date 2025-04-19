#include "type.h"
#include <stdlib.h>

fat32_t* new_fat32(){
    fat32_t* newFat = malloc(sizeof(fat32_t));
    *newFat = 1234;
    return newFat;
}
ext4_t* new_ext4(){
    ext4_t* newExt = malloc(sizeof(ext4_t));
    *newExt = 1234;
    return newExt;
}
ntfs_t* new_ntfs(){
    ntfs_t* newNtfs = malloc(sizeof(ntfs_t));
    *newNtfs = 1234;
    return newNtfs;
}
fat32_t* copy_fat32(fat32_t* file){
    fat32_t* copy = malloc(sizeof(fat32_t));
    *copy = *file;
    return copy;
}
ext4_t* copy_ext4(ext4_t* file){
    ext4_t* copy = malloc(sizeof(ext4_t));
    *copy = *file;
    return copy;
}
ntfs_t* copy_ntfs(ntfs_t* file){
    ntfs_t* copy = malloc(sizeof(ntfs_t));
    *copy = *file;
    return copy;
}
void rm_fat32(fat32_t* file){
    free(file);
}
void rm_ext4(ext4_t* file){
    free(file);
}
void rm_ntfs(ntfs_t* file){
    free(file);
}