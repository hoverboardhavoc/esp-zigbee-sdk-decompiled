/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zdo_command.o -> zdo_binding_table_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_binding_table_resp(int param_1)

{
  char cVar1;
  void *pvVar2;
  char *__src;
  char *pcVar3;
  char *pcVar4;
  void *pvVar5;
  void *__dest;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  undefined1 uStack_38;
  char cStack_37;
  char cStack_36;
  byte bStack_35;
  void *pvStack_34;
  
  pcVar3 = (char *)zb_buf_begin_func();
  cVar1 = *pcVar3;
  pcVar4 = (char *)esp_zb_zdo_callback_find(cVar1);
  if (pcVar3[1] == '\0') {
    zb_schedule_alarm_cancel(device_binding_table_req_timeout,cVar1,0);
  }
  pcVar6 = (code *)0x0;
  if (((pcVar4 != (char *)0x0) && (*pcVar4 == *pcVar3)) && (pcVar4[1] == '3')) {
    pcVar6 = *(code **)(pcVar4 + 4);
  }
  if ((pcVar3[1] == '\0') && (pcVar6 != (code *)0x0)) {
    cStack_36 = pcVar3[2];
    bStack_35 = pcVar3[4];
    uVar8 = (uint)bStack_35;
    __src = pcVar3 + 5;
    cStack_37 = pcVar3[3];
    uStack_38 = 0;
    pvStack_34 = (void *)0x0;
    pvVar5 = (void *)0x0;
    for (iVar7 = 0; iVar7 < (int)uVar8; iVar7 = iVar7 + 1) {
      __dest = malloc(0x1c);
      *(undefined2 *)((int)__dest + 10) = *(undefined2 *)(__src + 9);
      *(char *)((int)__dest + 0xc) = __src[0xb];
      *(char *)((int)__dest + 8) = __src[8];
      *(char *)((int)__dest + 0x16) = __src[0x14];
      memcpy(__dest,__src,8);
      memcpy((void *)((int)__dest + 0xe),__src + 0xc,8);
      *(undefined4 *)((int)__dest + 0x18) = 0;
      pvVar2 = __dest;
      if (pvVar5 != (void *)0x0) {
        *(void **)((int)pvVar5 + 0x18) = __dest;
        pvVar2 = pvStack_34;
      }
      pvStack_34 = pvVar2;
      __src = __src + 0x15;
      pvVar5 = __dest;
    }
    (*pcVar6)(&uStack_38,*(undefined4 *)(pcVar4 + 8));
    pvVar5 = pvStack_34;
    while (pvVar5 != (void *)0x0) {
      pvVar2 = *(void **)((int)pvVar5 + 0x18);
      free(pvVar5);
      pvVar5 = pvVar2;
    }
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  esp_zb_zdo_callback_remove(cVar1);
  return;
}

