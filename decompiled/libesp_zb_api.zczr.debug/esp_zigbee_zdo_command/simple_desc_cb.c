/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> simple_desc_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void simple_desc_cb(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined1 *__ptr;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  puVar3 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar3;
  __ptr = (undefined1 *)malloc(0xc);
  if (puVar3[1] == '\0') {
    uVar6 = (uint)(byte)puVar3[0xb] + (uint)(byte)puVar3[0xc] & 0xff;
    __ptr = (undefined1 *)realloc(__ptr,(uVar6 + 4) * 2);
    uVar2 = puVar3[9];
    __ptr[3] = puVar3[8];
    __ptr[4] = uVar2;
    __ptr[5] = __ptr[5] & 0xf0 | puVar3[10] & 0xf;
    __ptr[6] = puVar3[0xb];
    __ptr[7] = puVar3[0xc];
    uVar2 = puVar3[7];
    __ptr[1] = puVar3[6];
    __ptr[2] = uVar2;
    *__ptr = puVar3[5];
    for (iVar4 = 0; iVar4 < (int)uVar6; iVar4 = iVar4 + 1) {
      iVar5 = iVar4 * 2;
      uVar2 = puVar3[iVar5 + 0xe];
      __ptr[iVar5 + 8] = puVar3[iVar5 + 0xd];
      __ptr[iVar5 + 9] = uVar2;
    }
    zb_schedule_alarm_cancel(simple_desc_req_timeout,uVar1,0);
  }
  iVar4 = esp_zb_zdo_callback_find(uVar1);
  if (((iVar4 != 0) && (*(char *)(iVar4 + 1) == '\x04')) && (*(code **)(iVar4 + 4) != (code *)0x0))
  {
    (**(code **)(iVar4 + 4))(puVar3[1],__ptr,*(undefined4 *)(iVar4 + 8));
  }
  esp_zb_zdo_callback_remove(uVar1);
  free(__ptr);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

