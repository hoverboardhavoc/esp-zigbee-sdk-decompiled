/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> invalidate_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void invalidate_ctx(undefined4 *param_1)

{
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 1) = 0xff;
  *param_1 = 0;
  *(undefined1 *)((int)param_1 + 6) = 0;
  return;
}

