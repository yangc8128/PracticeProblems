/* [@bs.val] external fetch: string => Js.Promise.t('a) = "fetch"; */

type state =
  | LoadingOptions
  | ErrorFetchingOptions
  | LoadedOptions(array(string));

[@react.component]
let make = () => {
  let (state, setState) = React.useState(() => LoadingOptions);

  React.useEffect0(() => {
  /* setState(_previousState => LoadedOptions(Js.Array));
    setState(_previousState => ErrorFetchingOptions);
    setState(_previousState => LoadingOptions);
   */
    setState(_previousState => LoadedOptions([|"a", "b", "c"|]));
    None;
  });

  <div
    /* style={ReactDOMRe.Style.make(
      ~height="120px",
      ~display="flex",
      ~alignItems="center",
      ~justifyContent="center",
      (),
    )}*/
    >
    {
      switch (state) {
      | ErrorFetchingOptions => React.string("An error occurred!")
      | LoadingOptions => React.string("Loading...")
      | LoadedOptions(options) =>
        options
        ->Belt.Array.mapWithIndex((i, option) => {
          /* <div key=option > React.string(option)</div>; */
          <input
            id=option
            type_="checkbox"
            /* onClick={_ => self.sent(Toggle)} */
            /* checked=self.state.finished */
             />;
          <label htmlFor=option> (React.string(option)) </label>;
        })
        ->React.array
      }
    }
  </div>
}