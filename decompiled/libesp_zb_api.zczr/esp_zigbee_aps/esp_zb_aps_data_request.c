/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_aps.o -> esp_zb_aps_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_aps_data_request(undefined1 *param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  iVar1 = zb_buf_get_func(0,*(int *)(param_1 + 0x14) + 0x1a);
  if (iVar1 == 0) {
    uVar3 = 0x101;
  }
  else {
    pvVar2 = (void *)zb_buf_initial_alloc_func(*(undefined4 *)(param_1 + 0x14));
    memcpy(pvVar2,*(void **)(param_1 + 0x18),*(size_t *)(param_1 + 0x14));
    pvVar2 = (void *)zb_buf_get_tail_func(iVar1,0x1a);
    memset(pvVar2,0,0x1a);
    *(undefined1 *)((int)pvVar2 + 0xf) = *param_1;
    memcpy(pvVar2,param_1 + 2,8);
    *(undefined1 *)((int)pvVar2 + 0xc) = param_1[10];
    *(undefined2 *)((int)pvVar2 + 8) = *(undefined2 *)(param_1 + 0xc);
    *(undefined2 *)((int)pvVar2 + 10) = *(undefined2 *)(param_1 + 0xe);
    *(undefined1 *)((int)pvVar2 + 0xd) = param_1[0x10];
    *(undefined1 *)((int)pvVar2 + 0x11) = param_1[0x1d];
    *(undefined2 *)((int)pvVar2 + 0x12) = *(undefined2 *)(param_1 + 0x1e);
    *(char *)((int)pvVar2 + 0x14) = (char)*(undefined4 *)(param_1 + 0x20);
    *(undefined1 *)((int)pvVar2 + 0x10) = param_1[0x1c];
    *(undefined1 *)((int)pvVar2 + 0xe) = param_1[0x24];
    zb_buf_flags_or_func(iVar1,0x80);
    zb_schedule_callback(&zb_apsde_data_request,iVar1);
    uVar3 = 0;
  }
  return uVar3;
}

