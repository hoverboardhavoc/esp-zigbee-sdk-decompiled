/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_ping.o -> find_request_by_sn
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * find_request_by_sn(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (9 < iVar2) {
      return (undefined1 *)0x0;
    }
    iVar1 = iVar2 * 0x20;
    if (((&m_ping_request_table)[iVar1] != '\0') && ((byte)(&DAT_0001108a)[iVar1] == param_1))
    break;
    iVar2 = iVar2 + 1;
  }
  return &m_ping_request_table + iVar1;
}

