/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_general_cmd.o -> acquire_row_table
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int acquire_row_table(void)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (0x13 < iVar1) {
      return -1;
    }
    if ((&m_cmd_data)[iVar1 * 0x2e] == '\0') break;
    iVar1 = iVar1 + 1;
  }
  (&m_cmd_data)[iVar1 * 0x2e] = 1;
  return (int)(char)iVar1;
}

