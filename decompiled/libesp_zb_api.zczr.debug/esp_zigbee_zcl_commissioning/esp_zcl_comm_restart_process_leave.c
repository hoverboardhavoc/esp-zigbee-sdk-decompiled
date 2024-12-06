/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_comm_restart_process_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zcl_comm_restart_process_leave(undefined4 param_1)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  
  iVar3 = zb_buf_get_tail_func(0xb);
  zb_get_long_address();
  uVar2 = _DAT_000122e0;
  *(char *)(iVar3 + 8) = (char)_DAT_000122e0;
  *(char *)(iVar3 + 9) = (char)((ushort)uVar2 >> 8);
  bVar1 = *(byte *)(iVar3 + 10);
  *(byte *)(iVar3 + 10) = bVar1 & 0x7f;
  *(byte *)(iVar3 + 10) = bVar1 & 0x3f;
  zdo_mgmt_leave_req(param_1,esp_zcl_comm_restart_process_leave_done);
  return;
}

