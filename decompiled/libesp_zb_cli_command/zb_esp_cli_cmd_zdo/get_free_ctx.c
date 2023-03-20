/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> get_free_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * get_free_ctx(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (2 < uVar2) {
      return (undefined1 *)0x0;
    }
    iVar1 = uVar2 * 0xc;
    if (m_tsn_ctx[iVar1 + 5] == '\0') break;
    uVar2 = uVar2 + 1 & 0xff;
  }
  m_tsn_ctx[iVar1 + 5] = 1;
  return m_tsn_ctx + iVar1;
}

