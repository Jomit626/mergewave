# Event

The best feature of MergeWave is its custom event analysis on VCD files, which
helps designer summarizing signal changes into high level description.

## Event Attirbutes

An event can be synchronized to a clock or not. An asynchronized event is not
related to a clock and can be level-sensitive or edge-sensitive. A synchronized
event related to one certain clock means that the TODO: 

## Event Module

MergeWave uses systemverilg module to descripe an event.

## Asynchronize Event Definition

Below is an example of asynchronized level-sensitive event.

``` Systemverilg
/** MergeWave Event { # Event module identifier
  "interruption_assert" : { # name of event
    type: asynchronized, level-sensitive, # type of event
  },
  "interruption_deassert" : {
    type: asynchronized, level-sensitive, # TODO: use other representation
  }
} **/

module interruption_monitor # (
  parameter WIDTH = 8 // configurable
) (
  // custom input wires
  input wire [WIDTH-1:0] intvec,
  // formal output of event
  output wire event_interruption_assert,
  output wire event_interruption_deassert
);
  assign event_interruption_assert = |intvec;
  assign event_interruption_deassert = ~event_interruption_assert;
endmodule
```

