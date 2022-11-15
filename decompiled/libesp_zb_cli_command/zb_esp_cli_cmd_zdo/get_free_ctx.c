/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> get_free_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * get_free_ctx(void)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (2 < uVar1) {
      return (undefined1 *)0x0;
    }
    if (m_tsn_ctx[uVar1 * 0xc + 5] == '\0') break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  m_tsn_ctx[uVar1 * 0xc + 5] = 1;
  return m_tsn_ctx + uVar1 * 0xc;
}

