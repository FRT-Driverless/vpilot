#ifndef LAYOUT_H_
#define LAYOUT_H_

// CLAY includes
#include "clay.h"

// Custom includes
#include "actions.h"

// Components specific colors
const Clay_Color BTN_DRIVE = { 253, 218, 13, 255 };
const Clay_Color BTN_DRIVE_HOVER = { 253, 218, 13, 192 };

const Clay_Color BTN_NEUTRAL = { 0, 71, 171, 255 };
const Clay_Color BTN_NEUTRAL_HOVER = { 0, 71, 171, 192 };

const Clay_Color BTN_LAUNCH = { 210, 43, 43, 255 };
const Clay_Color BTN_LAUNCH_HOVER = { 210, 43, 43, 192 };

const Clay_Color BTN_FORCED_GEAR = { 242, 140, 40, 255 };
const Clay_Color BTN_FORCED_GEAR_HOVER = { 242, 140, 40, 192 };

const Clay_Color BTN_TAG = { 210, 43, 43, 255 };
const Clay_Color BTN_TAG_HOVER = { 210, 43, 43, 192 };

const Clay_Color BTN_OK = { 64, 128, 64, 255 };
const Clay_Color BTN_OK_HOVER = { 64, 128, 64, 192 };

const Clay_Color SELECTOR = { 64, 64, 64, 255 };
const Clay_Color SELECTOR_HOVER = { 64, 64, 64, 192 };

const Clay_Color GEAR_SHIFT = { 128, 128, 128, 255 };
const Clay_Color GEAR_SHIFT_HOVER = { 128, 128, 128, 192 };

// Generic colors
const Clay_Color COLOR_WHITE = { 255, 255, 255, 255 };
const Clay_Color COLOR_BLACK = { 0, 0, 0, 255 };
const Clay_Color COLOR_SOFT_BLACK = { 18, 18, 18, 255 };
const Clay_Color COLOR_RED = { 255, 0, 0, 255 };

Clay_RenderCommandArray vp_layout()
{
    // CLAY scope start
    Clay_BeginLayout();

    // Declarative layout
    CLAY({
        .layout = { 
            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
            .layoutDirection = CLAY_TOP_TO_BOTTOM,
        },
    }) {
        CLAY({
            .layout = { 
                .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_PERCENT(0.125) },
                .layoutDirection = CLAY_LEFT_TO_RIGHT,
            },
        }) {
            CLAY({
                .id = CLAY_ID("Drive Button"),
                .layout = {
                    .sizing = { .width = CLAY_SIZING_PERCENT(0.5), .height = CLAY_SIZING_GROW() },
                    .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER }
                },
                .backgroundColor = Clay_Hovered() ? BTN_DRIVE_HOVER : BTN_DRIVE,
            }) {
                Clay_OnHover(&ClayLogAction, (intptr_t) 0);
                CLAY_TEXT(
                    CLAY_STRING("DRIVE"),
                    CLAY_TEXT_CONFIG({
                        .fontSize = 24,
                        .textColor = COLOR_BLACK,
                    })
                );
            }
            CLAY({
                .id = CLAY_ID("Neutral Button"),
                .layout = {
                    .sizing = { .width = CLAY_SIZING_PERCENT(0.5), .height = CLAY_SIZING_GROW() },
                    .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER }
                },
                .backgroundColor = Clay_Hovered() ? BTN_NEUTRAL_HOVER : BTN_NEUTRAL,
            }) {
                Clay_OnHover(&ClayLogAction, (intptr_t) 0);
                CLAY_TEXT(
                    CLAY_STRING("NEUTRAL"),
                    CLAY_TEXT_CONFIG({
                        .fontSize = 24,
                        .textColor = COLOR_WHITE,
                    })
                );
            }
        }
        CLAY({
            .layout = { 
                .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_PERCENT(0.125) },
                .layoutDirection = CLAY_LEFT_TO_RIGHT,
            },
        }) {
            CLAY({
                .id = CLAY_ID("Launch Button"),
                .layout = {
                    .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                    .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                },
                .backgroundColor = Clay_Hovered() ? BTN_LAUNCH_HOVER : BTN_LAUNCH,
            }) {
                Clay_OnHover(&ClayLogAction, (intptr_t) 0);
                CLAY_TEXT(
                    CLAY_STRING("LAUNCH"),
                    CLAY_TEXT_CONFIG({
                        .fontSize = 24,
                        .textColor = COLOR_BLACK,
                    })
                );
            }
            CLAY({
                .id = CLAY_ID("Forced Gear Button"),
                .layout = {
                    .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                    .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                },
                .backgroundColor = Clay_Hovered() ? BTN_FORCED_GEAR_HOVER : BTN_FORCED_GEAR,
            }) {
                Clay_OnHover(&ClayLogAction, (intptr_t) 0);
                CLAY_TEXT(
                    CLAY_STRING("FORCED GEAR"),
                    CLAY_TEXT_CONFIG({
                        .fontSize = 24,
                        .textColor = COLOR_BLACK,
                    })
                );
            }
            CLAY({
                .id = CLAY_ID("Tag Button"),
                .layout = {
                    .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                    .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER }
                },
                .backgroundColor = Clay_Hovered() ? BTN_TAG_HOVER : BTN_TAG,
            }) {
                Clay_OnHover(&ClayLogAction, (intptr_t) 0);
                CLAY_TEXT(
                    CLAY_STRING("TAG"),
                    CLAY_TEXT_CONFIG({
                        .fontSize = 24,
                        .textColor = COLOR_BLACK,
                    })
                );
            }
        }
        CLAY({
            .layout = { 
                .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                .layoutDirection = CLAY_TOP_TO_BOTTOM,
            },
        }) {
            // Top row
            CLAY({
                .layout = { 
                    .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                    .layoutDirection = CLAY_LEFT_TO_RIGHT,
                },
            }) {
                CLAY({
                    .layout = { 
                        .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                        .layoutDirection = CLAY_TOP_TO_BOTTOM,
                    },
                }) {
                    CLAY({
                        .layout = {
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_PERCENT(0.33) },
                            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                        },
                        .border = {
                            .color = COLOR_WHITE,
                            .width = CLAY_BORDER_ALL(2),
                        },
                    }) {
                        CLAY_TEXT(
                            CLAY_STRING("ENGINE RPM"),
                            CLAY_TEXT_CONFIG({
                                .fontSize = 18,
                                .textColor = COLOR_RED,
                            })
                        );
                    }
                    CLAY({
                        .layout = {
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                        },
                        .border = {
                            .color = COLOR_WHITE,
                            .width = CLAY_BORDER_ALL(2),
                        },
                    }) {
                        CLAY_TEXT(
                            CLAY_STRING("0"),
                            CLAY_TEXT_CONFIG({
                                .fontSize = 36,
                                .textColor = COLOR_WHITE,
                            })
                        );
                    }
                }
                CLAY({
                    .layout = { 
                        .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                        .layoutDirection = CLAY_TOP_TO_BOTTOM,
                        .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                    },
                }) {
                    CLAY({
                        .layout = {
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                        },
                        .border = {
                            .color = COLOR_WHITE,
                            .width = CLAY_BORDER_ALL(2),
                        },
                    }) {
                        CLAY_TEXT(
                            CLAY_STRING("0"),
                            CLAY_TEXT_CONFIG({
                                .fontSize = 36,
                                .textColor = COLOR_WHITE,
                            })
                        );
                    }
                }
                CLAY({
                    .layout = { 
                        .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                        .layoutDirection = CLAY_TOP_TO_BOTTOM,
                    },
                }) {
                    CLAY({
                        .layout = {
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_PERCENT(0.33) },
                            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                        },
                        .border = {
                            .color = COLOR_WHITE,
                            .width = CLAY_BORDER_ALL(2),
                        },
                    }) {
                        CLAY_TEXT(
                            CLAY_STRING("WTS"),
                            CLAY_TEXT_CONFIG({
                                .fontSize = 18,
                                .textColor = COLOR_RED,
                            })
                        );
                    }
                    CLAY({
                        .layout = {
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                        },
                        .border = {
                            .color = COLOR_WHITE,
                            .width = CLAY_BORDER_ALL(2),
                        },
                    }) {
                        CLAY_TEXT(
                            CLAY_STRING("0"),
                            CLAY_TEXT_CONFIG({
                                .fontSize = 36,
                                .textColor = COLOR_WHITE,
                            })
                        );
                    }
                }
            }
            // Center row
            CLAY({
                .layout = { 
                    .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                    .layoutDirection = CLAY_LEFT_TO_RIGHT,
                },
                .border = {
                    .color = COLOR_WHITE,
                    .width = CLAY_BORDER_ALL(2),
                },
            }) {
                CLAY({
                    .layout = { 
                        .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                        .layoutDirection = CLAY_TOP_TO_BOTTOM,
                    },
                }) {
                    CLAY({
                        .layout = { 
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                            .layoutDirection = CLAY_LEFT_TO_RIGHT,
                        },
                    }) {
                        CLAY({
                            .layout = {
                                .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                                .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                            },
                            .border = {
                                .color = COLOR_WHITE,
                                .width = { 2, 0, 2, 2, 2 },
                            },
                        }) {
                            CLAY_TEXT(
                                CLAY_STRING("OPS"),
                                CLAY_TEXT_CONFIG({
                                    .fontSize = 18,
                                    .textColor = COLOR_WHITE,
                                })
                            );
                        }
                        CLAY({
                            .layout = {
                                .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                                .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                            },
                            .border = {
                                .color = COLOR_WHITE,
                                .width = { 0, 2, 2, 2, 2 },
                            },
                        }) {
                            CLAY_TEXT(
                                CLAY_STRING("0"),
                                CLAY_TEXT_CONFIG({
                                    .fontSize = 18,
                                    .textColor = COLOR_WHITE,
                                })
                            );
                        }
                    }
                    CLAY({
                        .layout = { 
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                            .layoutDirection = CLAY_LEFT_TO_RIGHT,
                        },
                    }) {
                        CLAY({
                            .layout = {
                                .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                                .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                            },
                            .border = {
                                .color = COLOR_WHITE,
                                .width = { 2, 0, 2, 2, 2 },
                            },
                        }) {
                            CLAY_TEXT(
                                CLAY_STRING("MAPS"),
                                CLAY_TEXT_CONFIG({
                                    .fontSize = 18,
                                    .textColor = COLOR_WHITE,
                                })
                            );
                        }
                        CLAY({
                            .layout = {
                                .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                                .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                            },
                            .border = {
                                .color = COLOR_WHITE,
                                .width = { 0, 2, 2, 2, 2 },
                            },
                        }) {
                            CLAY_TEXT(
                                CLAY_STRING("0"),
                                CLAY_TEXT_CONFIG({
                                    .fontSize = 18,
                                    .textColor = COLOR_WHITE,
                                })
                            );
                        }
                    }
                    CLAY({
                        .layout = { 
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                            .layoutDirection = CLAY_LEFT_TO_RIGHT,
                        },
                    }) {
                        CLAY({
                            .layout = {
                                .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                                .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                            },
                            .border = {
                                .color = COLOR_WHITE,
                                .width = { 2, 0, 2, 2, 2 },
                            },
                        }) {
                            CLAY_TEXT(
                                CLAY_STRING("FPS"),
                                CLAY_TEXT_CONFIG({
                                    .fontSize = 18,
                                    .textColor = COLOR_WHITE,
                                })
                            );
                        }
                        CLAY({
                            .layout = {
                                .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                                .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                            },
                            .border = {
                                .color = COLOR_WHITE,
                                .width = { 0, 2, 2, 2, 2 },
                            },
                        }) {
                            CLAY_TEXT(
                                CLAY_STRING("0"),
                                CLAY_TEXT_CONFIG({
                                    .fontSize = 18,
                                    .textColor = COLOR_WHITE,
                                })
                            );
                        }
                    }
                    CLAY({
                        .layout = { 
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                            .layoutDirection = CLAY_LEFT_TO_RIGHT,
                        },
                    }) {
                        CLAY({
                            .layout = {
                                .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                                .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                            },
                            .border = {
                                .color = COLOR_WHITE,
                                .width = { 2, 0, 2, 2, 2 },
                            },
                        }) {
                            CLAY_TEXT(
                                CLAY_STRING("12V"),
                                CLAY_TEXT_CONFIG({
                                    .fontSize = 18,
                                    .textColor = COLOR_WHITE,
                                })
                            );
                        }
                        CLAY({
                            .layout = {
                                .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                                .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                            },
                            .border = {
                                .color = COLOR_WHITE,
                                .width = { 0, 2, 2, 2, 2 },
                            },
                        }) {
                            CLAY_TEXT(
                                CLAY_STRING("0"),
                                CLAY_TEXT_CONFIG({
                                    .fontSize = 18,
                                    .textColor = COLOR_WHITE,
                                })
                            );
                        }
                    }
                }
                CLAY({
                    .layout = { 
                        .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                        .layoutDirection = CLAY_TOP_TO_BOTTOM,
                    },
                }) {
                    CLAY({
                        .layout = {
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_PERCENT(0.33) },
                            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                        },
                        .backgroundColor = COLOR_WHITE,
                        .border = {
                            .color = COLOR_WHITE,
                            .width = CLAY_BORDER_ALL(2),
                        },
                    }) {
                        CLAY_TEXT(
                            CLAY_STRING("GEAR"),
                            CLAY_TEXT_CONFIG({
                                .fontSize = 18,
                                .textColor = COLOR_BLACK,
                            })
                        );
                    }
                    CLAY({
                        .layout = {
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                        },
                        .border = {
                            .color = COLOR_WHITE,
                            .width = CLAY_BORDER_ALL(2),
                        },
                    }) {
                        CLAY_TEXT(
                            CLAY_STRING("N"),
                            CLAY_TEXT_CONFIG({
                                .fontSize = 48,
                                .textColor = COLOR_WHITE,
                            })
                        );
                    }
                }
                CLAY({
                    .layout = { 
                        .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                        .layoutDirection = CLAY_TOP_TO_BOTTOM,
                    },
                }) {
                    CLAY({
                        .layout = {
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_PERCENT(0.33) },
                            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                        },
                        .border = {
                            .color = COLOR_WHITE,
                            .width = CLAY_BORDER_ALL(2),
                        },
                    }) {
                        CLAY_TEXT(
                            CLAY_STRING("BRAKE BIAS"),
                            CLAY_TEXT_CONFIG({
                                .fontSize = 18,
                                .textColor = COLOR_RED,
                            })
                        );
                    }
                    CLAY({
                        .layout = {
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                        },
                        .border = {
                            .color = COLOR_WHITE,
                            .width = CLAY_BORDER_ALL(2),
                        },
                    }) {
                        CLAY_TEXT(
                            CLAY_STRING("0%"),
                            CLAY_TEXT_CONFIG({
                                .fontSize = 36,
                                .textColor = COLOR_WHITE,
                            })
                        );
                    }
                }
            }
            // Bottom row
            CLAY({
                .layout = { 
                    .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                    .layoutDirection = CLAY_LEFT_TO_RIGHT,
                },
            }) {
                CLAY({
                    .layout = { 
                        .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                    },
                    .border = {
                        .color = COLOR_WHITE,
                        .width = CLAY_BORDER_ALL(2),
                    },
                }) {
                }
                CLAY({
                    .layout = { 
                        .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                        .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                    },
                    .border = {
                        .color = COLOR_WHITE,
                        .width = CLAY_BORDER_ALL(2),
                    },
                }) {
                    CLAY_TEXT(
                        CLAY_STRING("ERROR LOGS INSIDE TERMINAL"),
                        CLAY_TEXT_CONFIG({
                            .fontSize = 18,
                            .textColor = COLOR_RED,
                        })
                    );
                }
            }
        }
        CLAY({
            .layout = { 
                .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_PERCENT(0.25) },
                .layoutDirection = CLAY_LEFT_TO_RIGHT,
            },
        }) {
            CLAY({
                .id = CLAY_ID("Gear Down Button"),
                .layout = { 
                    .sizing = { .width = CLAY_SIZING_PERCENT(0.3), .height = CLAY_SIZING_GROW() },
                    .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                },
                .backgroundColor = Clay_Hovered() ?  GEAR_SHIFT_HOVER : GEAR_SHIFT,
            }) {
                Clay_OnHover(&ClayLogAction, (intptr_t) 0);
                CLAY_TEXT(
                    CLAY_STRING("DOWN"),
                    CLAY_TEXT_CONFIG({
                        .fontSize = 24,
                        .textColor = COLOR_BLACK,
                    })
                );
            }
            CLAY({
                .layout = { 
                    .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                    .layoutDirection = CLAY_TOP_TO_BOTTOM,
                },
            }) {
                CLAY({
                    .id = CLAY_ID("Ok Button"),
                    .layout = {
                        .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                        .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                    },
                    .backgroundColor = Clay_Hovered() ? BTN_OK_HOVER : BTN_OK,
                }) {
                    Clay_OnHover(&ClayLogAction, (intptr_t) 0);
                    CLAY_TEXT(
                        CLAY_STRING("OK"),
                        CLAY_TEXT_CONFIG({
                            .fontSize = 24,
                            .textColor = COLOR_WHITE,
                        })
                    );
                }
                CLAY({
                    .layout = {
                        .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                    },
                }) {
                    CLAY({
                        .id = CLAY_ID("Gas Curve Selector"),
                        .layout = { 
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                        },
                        .backgroundColor = Clay_Hovered() ? SELECTOR_HOVER : SELECTOR,
                    }) {
                        Clay_OnHover(&ClayLogAction, (intptr_t) 0);
                        CLAY_TEXT(
                            CLAY_STRING("GAS CURVE"),
                            CLAY_TEXT_CONFIG({
                                .fontSize = 24,
                                .textColor = COLOR_WHITE,
                            })
                        );
                    }
                    CLAY({
                        .id = CLAY_ID("Mission Selector"),
                        .layout = { 
                            .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                            .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                        },
                        .backgroundColor = Clay_Hovered() ? SELECTOR_HOVER : SELECTOR,
                    }) {
                        Clay_OnHover(&ClayLogAction, (intptr_t) 0);
                        CLAY_TEXT(
                            CLAY_STRING("MISSION"),
                            CLAY_TEXT_CONFIG({
                                .fontSize = 24,
                                .textColor = COLOR_WHITE,
                            })
                        );
                    }
                }
            }
            CLAY({
                .id = CLAY_ID("Gear Up Button"),
                .layout = { 
                    .sizing = { .width = CLAY_SIZING_PERCENT(0.3), .height = CLAY_SIZING_GROW() },
                    .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                },
                .backgroundColor = Clay_Hovered() ? GEAR_SHIFT_HOVER : GEAR_SHIFT,
            }) {
                Clay_OnHover(&ClayLogAction, (intptr_t) 0);
                CLAY_TEXT(
                    CLAY_STRING("UP"),
                    CLAY_TEXT_CONFIG({
                        .fontSize = 24,
                        .textColor = COLOR_BLACK,
                    })
                );
            }
        }
    }

    // CLAY scope end, it returns the commands to render the layout
    return Clay_EndLayout();
}

#endif // LAYOUT_H_
