/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> zdo_binding_table_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_binding_table_resp(int param_1)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  code *pcVar6;
  undefined1 uStack_3c;
  char cStack_3b;
  char cStack_3a;
  char cStack_39;
  char cStack_38;
  char cStack_37;
  char cStack_36;
  char cStack_35;
  char cStack_34;
  char cStack_33;
  char cStack_32;
  char cStack_31;
  char cStack_30;
  undefined2 uStack_2e;
  char cStack_2c;
  char cStack_2a;
  char cStack_29;
  char cStack_28;
  char cStack_27;
  char cStack_26;
  char cStack_25;
  char cStack_24;
  char cStack_23;
  char cStack_22;
  
  pcVar3 = (char *)zb_buf_begin_func();
  pcVar4 = (char *)esp_zb_zdo_callback_find(*pcVar3);
  if ((pcVar3[1] == '\0') &&
     (iVar2 = zb_schedule_alarm_cancel(device_binding_table_req_timeout,0xff,0), iVar2 != 0)) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC20,uVar5,0x10000,"zdo_binding_table_resp",0x31a);
  }
  else {
    if (pcVar4 == (char *)0x0) {
      pcVar6 = (code *)0x0;
    }
    else if (*pcVar4 == *pcVar3) {
      if (pcVar4[1] == '3') {
        pcVar6 = *(code **)(pcVar4 + 4);
      }
      else {
        pcVar6 = (code *)0x0;
      }
    }
    else {
      pcVar6 = (code *)0x0;
    }
    if ((pcVar3[1] == '\0') && (pcVar6 != (code *)0x0)) {
      bVar1 = pcVar3[4];
      pcVar4 = pcVar3 + 5;
      cStack_3a = counter_0;
      cStack_3b = pcVar3[2];
      cStack_39 = pcVar3[3];
      uStack_3c = 0;
      for (iVar2 = 0; iVar2 < (int)(uint)bVar1; iVar2 = iVar2 + 1) {
        cStack_3a = cStack_3a + '\x01';
        uStack_2e = *(undefined2 *)(pcVar4 + 9);
        cStack_2c = pcVar4[0xb];
        cStack_30 = pcVar4[8];
        cStack_22 = pcVar4[0x14];
        cStack_38 = *pcVar4;
        cStack_37 = pcVar4[1];
        cStack_36 = pcVar4[2];
        cStack_35 = pcVar4[3];
        cStack_34 = pcVar4[4];
        cStack_33 = pcVar4[5];
        cStack_32 = pcVar4[6];
        cStack_31 = pcVar4[7];
        cStack_2a = pcVar4[0xc];
        cStack_29 = pcVar4[0xd];
        cStack_28 = pcVar4[0xe];
        cStack_27 = pcVar4[0xf];
        cStack_26 = pcVar4[0x10];
        cStack_25 = pcVar4[0x11];
        cStack_24 = pcVar4[0x12];
        cStack_23 = pcVar4[0x13];
        (*pcVar6)(&uStack_3c,0);
        pcVar4 = pcVar4 + 0x15;
      }
      counter_0 = bVar1 + counter_0;
    }
    else {
      counter_0 = '\0';
    }
    if (param_1 != 0) {
      zb_buf_free_func(param_1);
    }
  }
  return;
}

