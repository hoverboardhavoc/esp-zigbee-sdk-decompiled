/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zb_bdb_open_local_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void zb_bdb_open_local_network(undefined4 param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
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
    uVar2 = _DAT_0001a318;
    if (iVar4 != 0) {
      *puVar5 = (char)_DAT_0001a318;
      puVar5[1] = (char)((ushort)uVar2 >> 8);
      puVar5[2] = uVar1;
      puVar5[3] = 0;
      zb_zdo_mgmt_permit_joining_req(param_1,0);
    }
  }
  return;
}

