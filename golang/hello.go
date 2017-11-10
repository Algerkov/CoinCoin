package main

import (
	"fmt"
	"log"
	"math/rand"
	"strings"
	"time"
	//"bytes"
	"crypto/sha1"
	"strconv"
	//"bufio"
	//"io/ioutil"
	"os"
	//"log"
)

/*
func init() {
	rand.Seed(time.Now().UnixNano())
}
*/
//var letterRunes = []rune("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
var letterBytes = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+=?-$€"

func RandStringBytesRmndr(n int) string {
	b := make([]byte, n)
	for i := range b {
		b[i] = letterBytes[rand.Int63()%int64(len(letterBytes))]
	}
	return string(b)
}

func writePurse(arkenstone string) {

	file, err := os.Create("purses.txt")
	if err != nil {
		log.Fatal(arkenstone, err)
	}
	defer file.Close()
	fmt.Fprintf(file, arkenstone+"\n")
}

func replaceAtIndex(in string, r rune, i int) string {
	out := []rune(in)
	out[i] = r
	return string(out)
}

func main() {
	//i := 0
	coinBase := "12345678912345678912gfedcbaE"

	//	for i < 10000000 {
	for {
		gen4 := RandStringBytesRmndr(4)
		coin := coinBase + gen4
		coin += "-FDU"
		coin += "-CC1.0-"
		tmp := time.Now().Unix()
		coin += strconv.Itoa(int(tmp))
		coin += "-0f0f0f"
		//fmt.Printf(coin)
		h := sha1.New()
		h.Write([]byte(coin))
		bs := h.Sum(nil)
		//fmt.Printf(" %x", bs)
		tmpString := fmt.Sprintf("%x", bs)
		//fmt.Printf(tmpString)

		if strings.HasPrefix(tmpString, "ccccccccc") {
			fmt.Printf(coin + "\n")
			writePurse(coin)
		}
		//i++
	}
}
