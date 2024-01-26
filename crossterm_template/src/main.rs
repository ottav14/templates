use std::io;
use crossterm::{
    execute, cursor, terminal,
    style::{self, Stylize},
    event::{read, Event, KeyEvent, KeyCode::Char}
};

fn main() -> io::Result<()> {

    let mut stdout = io::stdout();
    terminal::enable_raw_mode();
    execute!(
        stdout,
        terminal::EnterAlternateScreen,
        cursor::Hide
    )?;

    loop {
        if let Event::Key(event) = read()? {
             match event.code {
                 Char('q') => {
                     break;
                 }
                 _ => {
                     continue;
                 }
             }
        }
    }

    execute!(
        stdout,
        terminal::LeaveAlternateScreen,
        cursor::Show
    )?;
    terminal::disable_raw_mode();

    Ok(())

}
