
import Data.List

--driver
main :: IO()
main = do 
    let floats = [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26]
    print $ mySort float_comp floats
    let people = createPeople
    print $ compare (personName (people!!1)) (personName (people!!0))
    print $ mySort people_comp people


                                --Person Class--
data Person = Person String Int deriving Show
    --data members--
personAge :: Person -> Int 
personName :: Person -> String
personAge (Person _ a) = a
personName (Person n _) = n

    --implementation of Eq --
instance Eq Person where 
    (Person n1 a1) == (Person n2 a2) = n1 == n2 && a1 == a2

--Comparator function for Person objects
people_comp :: Person->Person->Ordering
people_comp a b     | personAge a == personAge b = compare (personName a) (personName b)
                    | otherwise = compare (personAge a) (personAge b)
                                 --Person Class--


--Custom sorting generic function
--takes a comparator function and a list of elements, returns a list of elements
mySort :: (a->a->Ordering)->[a] -> [a]
mySort _ [] = []
mySort compFunc xs  = sortBy compFunc xs


-- function to create a list of Person objects
createPeople :: [Person] 
createPeople = [Person "Mac "19, Person "Hal" 20, Person "Sussan" 31, Person "Dwight" 19, Person "Kassandra" 21, Person "Lawrence" 25, Person "Cindy" 22, 
          Person "Cory" 27,  Person "Romana" 27, Person "Doretha" 32, Person "Danna" 20, Person "Zara" 23, Person "Rosalyn" 26, 
           Person "Risa" 24, Person "Benny" 28, Person "Juan" 33, Person "Natalie" 25]

--Comparator function for Floats 
float_comp :: Float->Float->Ordering
float_comp a b = compare a b