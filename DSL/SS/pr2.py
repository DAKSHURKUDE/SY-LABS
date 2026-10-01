def selection_sort(values):
    for index in range(len(values) - 1):
        minimum = index
        for next_index in range(index + 1, len(values)):
            if values[next_index] < values[minimum]:
                minimum = next_index
        values[index], values[minimum] = values[minimum], values[index]


def insertion_sort(values):
    for index in range(1, len(values)):
        key = values[index]
        previous = index - 1
        while previous >= 0 and values[previous] > key:
            values[previous + 1] = values[previous]
            previous -= 1
        values[previous + 1] = key


def bubble_sort(values):
    for index in range(len(values) - 1):
        for next_index in range(len(values) - index - 1):
            if values[next_index] > values[next_index + 1]:
                values[next_index], values[next_index + 1] = (
                    values[next_index + 1], values[next_index]
                )


print("Enter the number of students:")
number_of_students = int(input())
print("Enter the percentage of Students:")
percentages = [float(input()) for _ in range(number_of_students)]

print(
    "Enter the Sort to be Performed:\n"
    "1 - Selection Sort\n"
    "2 - Bubble Sort\n"
    "3 - Insertion Sort\n"
    "Enter : ",
    end="",
)
choice = int(input())

match choice:
    case 1:
        sort_function, sort_name = selection_sort, "Selection"
    case 2:
        sort_function, sort_name = bubble_sort, "Bubble"
    case 3:
        sort_function, sort_name = insertion_sort, "Insertion"
    case _:
        sort_function = None
        print("Invalid choice!!", end="")

if sort_function is not None:
    sort_function(percentages)

    print(f"Sorted array using {sort_name} Sort:")
    print("".join(f"{percentage:.2f} " for percentage in percentages))

    print("\nTop Five Students:")
    for percentage in reversed(percentages[-5:]):
        print(f"{percentage:.2f}")