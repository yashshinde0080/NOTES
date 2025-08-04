import wikipedia 

def get_info(query):
    try:
        # Get a brief summary (3 sentences)
        summary = wikipedia.summary(query, sentences=3)
        return summary
    except wikipedia.exceptions.DisambiguationError as e:
        return f"Your query is ambiguous. Suggestions: {e.options[:5]}"
    except wikipedia.exceptions.PageError:
        return "No page found for the given query."
    except Exception as e:
        return f"An error occurred: {str(e)}"

def run_bot():
    print("Text Info Bot (powered by Wikipedia)")
    print("Type 'exit' to quit.\n")

    while True:
        query = input("Enter your search text: ").strip()
        if query.lower() == 'exit':
            print("Goodbye!")
            break
        if query:
            print("\n Outcome:\n")
            print(get_info(query))
            print("\n" + "-"*50 + "\n")
        else:
            print("Please enter a valid query.\n")

if __name__ == "__main__":
    run_bot()
