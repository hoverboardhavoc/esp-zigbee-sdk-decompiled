/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> zb_bdb_open_local_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_bdb_open_local_network(undefined4 param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  undefined1 *puVar5;
  
  cVar3 = zb_buf_get_status_func();
  iVar4 = zb_buf_begin_func(param_1);
  uVar1 = *(undefined1 *)(iVar4 + 1);
  iVar4 = zb_zdo_joined();
  if ((iVar4 != 0) && (cVar3 == '\0')) {
    puVar5 = (undefined1 *)zb_buf_get_tail_func(param_1,4);
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    iVar4 = zb_is_device_zc_or_zr();
    if (iVar4 != 0) {
      *puVar5 = DAT_0001230c;
      uVar2 = DAT_0001230d;
      puVar5[2] = uVar1;
      puVar5[3] = 0;
      puVar5[1] = uVar2;
      zb_zdo_mgmt_permit_joining_req(param_1,0);
      return;
    }
  }
  return;
}

