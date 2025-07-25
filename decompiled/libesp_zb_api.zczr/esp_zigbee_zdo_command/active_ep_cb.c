/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zdo_command.o -> active_ep_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void active_ep_cb(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  void *__ptr;
  int iVar4;
  
  puVar3 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar3;
  __ptr = calloc(1,1);
  uVar2 = ZDO_INVALID_ENDPOINT;
  if (puVar3[1] == '\0') {
    __ptr = realloc(__ptr,(uint)(byte)puVar3[4]);
    uVar2 = puVar3[4];
    for (iVar4 = 0; iVar4 < (int)(uint)(byte)puVar3[4]; iVar4 = iVar4 + 1) {
      *(undefined1 *)((int)__ptr + iVar4) = puVar3[iVar4 + 5];
    }
    zb_schedule_alarm_cancel(active_ep_req_timeout,uVar1,0);
  }
  iVar4 = esp_zb_zdo_callback_find(uVar1);
  if (((iVar4 != 0) && (*(short *)(iVar4 + 2) == 5)) && (*(code **)(iVar4 + 4) != (code *)0x0)) {
    (**(code **)(iVar4 + 4))(puVar3[1],uVar2,__ptr,*(undefined4 *)(iVar4 + 8));
  }
  esp_zb_zdo_callback_remove(uVar1);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  free(__ptr);
  return;
}

