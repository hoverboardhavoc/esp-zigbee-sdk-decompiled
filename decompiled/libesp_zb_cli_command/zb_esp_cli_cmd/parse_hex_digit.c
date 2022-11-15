/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd.o -> parse_hex_digit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte parse_hex_digit(char param_1)

{
  byte bVar1;
  
  bVar1 = param_1 - 0x30;
  if (9 < bVar1) {
    if ((byte)(param_1 + 0x9fU) < 6) {
      return param_1 + 0xa9;
    }
    if ((byte)(param_1 + 0xbfU) < 6) {
      return param_1 - 0x37;
    }
    bVar1 = 0xff;
  }
  return bVar1;
}

