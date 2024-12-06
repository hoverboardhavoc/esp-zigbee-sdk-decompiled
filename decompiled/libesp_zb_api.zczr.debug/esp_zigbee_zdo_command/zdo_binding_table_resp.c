/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> zdo_binding_table_resp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_binding_table_resp(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  char *pcVar14;
  uint uVar15;
  code *pcVar16;
  undefined1 uStack_38;
  char cStack_37;
  char cStack_36;
  byte bStack_35;
  char *pcStack_34;
  
  pcVar12 = (char *)zb_buf_begin_func();
  cVar1 = *pcVar12;
  pcVar13 = (char *)esp_zb_zdo_callback_find(cVar1);
  if (pcVar12[1] == '\0') {
    zb_schedule_alarm_cancel(device_binding_table_req_timeout,cVar1,0);
  }
  if (pcVar13 == (char *)0x0) {
    pcVar16 = (code *)0x0;
  }
  else if (*pcVar13 == *pcVar12) {
    if (pcVar13[1] == '3') {
      pcVar16 = *(code **)(pcVar13 + 4);
    }
    else {
      pcVar16 = (code *)0x0;
    }
  }
  else {
    pcVar16 = (code *)0x0;
  }
  if ((pcVar12[1] == '\0') && (pcVar16 != (code *)0x0)) {
    bStack_35 = pcVar12[4];
    uVar15 = (uint)bStack_35;
    pcVar10 = pcVar12 + 5;
    cStack_36 = pcVar12[2];
    cStack_37 = pcVar12[3];
    pcStack_34 = (char *)0x0;
    uStack_38 = 0;
    pcVar12 = (char *)0x0;
    for (iVar11 = 0; iVar11 < (int)uVar15; iVar11 = iVar11 + 1) {
      pcVar14 = (char *)malloc(0x1c);
      *(undefined2 *)(pcVar14 + 10) = *(undefined2 *)(pcVar10 + 9);
      pcVar14[0xc] = pcVar10[0xb];
      pcVar14[8] = pcVar10[8];
      pcVar14[0x16] = pcVar10[0x14];
      cVar2 = pcVar10[1];
      cVar3 = pcVar10[2];
      cVar4 = pcVar10[3];
      cVar5 = pcVar10[4];
      cVar6 = pcVar10[5];
      cVar7 = pcVar10[6];
      cVar8 = pcVar10[7];
      *pcVar14 = *pcVar10;
      pcVar14[1] = cVar2;
      pcVar14[2] = cVar3;
      pcVar14[3] = cVar4;
      pcVar14[4] = cVar5;
      pcVar14[5] = cVar6;
      pcVar14[6] = cVar7;
      pcVar14[7] = cVar8;
      cVar2 = pcVar10[0xd];
      cVar3 = pcVar10[0xe];
      cVar4 = pcVar10[0xf];
      cVar5 = pcVar10[0x10];
      cVar6 = pcVar10[0x11];
      cVar7 = pcVar10[0x12];
      cVar8 = pcVar10[0x13];
      pcVar14[0xe] = pcVar10[0xc];
      pcVar14[0xf] = cVar2;
      pcVar14[0x10] = cVar3;
      pcVar14[0x11] = cVar4;
      pcVar14[0x12] = cVar5;
      pcVar14[0x13] = cVar6;
      pcVar14[0x14] = cVar7;
      pcVar14[0x15] = cVar8;
      pcVar14[0x18] = '\0';
      pcVar14[0x19] = '\0';
      pcVar14[0x1a] = '\0';
      pcVar14[0x1b] = '\0';
      pcVar9 = pcVar14;
      if (pcVar12 != (char *)0x0) {
        *(char **)(pcVar12 + 0x18) = pcVar14;
        pcVar9 = pcStack_34;
      }
      pcStack_34 = pcVar9;
      pcVar10 = pcVar10 + 0x15;
      pcVar12 = pcVar14;
    }
    (*pcVar16)(&uStack_38,*(undefined4 *)(pcVar13 + 8));
    pcVar12 = pcStack_34;
    while (pcVar12 != (char *)0x0) {
      pcVar13 = *(char **)(pcVar12 + 0x18);
      free(pcVar12);
      pcVar12 = pcVar13;
    }
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  esp_zb_zdo_callback_remove(cVar1);
  return;
}

