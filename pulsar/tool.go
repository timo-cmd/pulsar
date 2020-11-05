package main

import (
	"fmt"
    "os"
    "path/filepath"
    "math/rand"
    "log"
)

func Walk(absoultePath string, do func(path string)) {
    var files []string
    var err error
    
    if !filepath.IsAbs(absoultePath) {
        absoultePath, err = filepath.Abs(absoultePath)
        if err != nil{
            log.Fatal(err)
            return 
        }
    }
    
    fmt.Println("walking ...", absoultePath)
    if Exists(absoultePath) == false{
        log.Fatal(absoultePath, "is not exists directory.")
    }

    err = filepath.Walk(absoultePath, func(path string, info os.FileInfo, err error) error {
		if !info.IsDir(){
			files = append(files, path)
		}
        return nil
    })
    if err != nil {
        log.Fatal(err)
        return
    }
    for _, path := range files {
		do(path)
    }
}

func Exists(name string) bool {
    if _, err := os.Stat(name); err != nil {
        if os.IsNotExist(err) {
            return false
        }
    }
    return true
}

func StringInSlice(a string, list []string) bool {
    for _, b := range list {
        if b == a {
            return true
        }
    }
    return false
}
var letters = []rune("1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")

func randSeq(n int) string {
    b := make([]rune, n)
    for i := range b {
        b[i] = letters[rand.Intn(len(letters))]
    }
    return string(b)
}

func getdrives() (r []string){
    for _, drive := range "ABCDEFGHIJKLMNOPQRSTUVWXYZ"{
        _, err := os.Open(string(drive)+":\\")
        if err == nil {
            r = append(r, string(drive))
        }
    }
    return
}