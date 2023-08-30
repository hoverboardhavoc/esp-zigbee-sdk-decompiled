/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> simple_desc_cb
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
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  puVar3 = (undefined1 *)zb_buf_begin_func();
  uVar1 = *puVar3;
  __ptr = (undefined1 *)malloc(0xc);
  if (puVar3[1] == '\0') {
    uVar7 = (uint)(byte)puVar3[0xb] + (uint)(byte)puVar3[0xc] & 0xff;
    __ptr = (undefined1 *)realloc(__ptr,(uVar7 + 4) * 2);
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
    for (iVar5 = 0; iVar5 < (int)uVar7; iVar5 = iVar5 + 1) {
      iVar6 = iVar5 * 2;
      uVar2 = puVar3[iVar6 + 0xe];
      __ptr[iVar6 + 8] = puVar3[iVar6 + 0xd];
      __ptr[iVar6 + 9] = uVar2;
    }
    iVar5 = zb_schedule_alarm_cancel(simple_desc_req_timeout,0xff,0);
    if (iVar5 != 0) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_L0,uVar4,0x10000,"simple_desc_cb",0x284);
      return;
    }
  }
  iVar5 = esp_zb_zdo_callback_find(uVar1);
  if (((iVar5 != 0) && (*(char *)(iVar5 + 1) == '\x04')) && (*(code **)(iVar5 + 4) != (code *)0x0))
  {
    (**(code **)(iVar5 + 4))(puVar3[1],__ptr,*(undefined4 *)(iVar5 + 8));
  }
  esp_zb_zdo_callback_remove(uVar1);
  free(__ptr);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

