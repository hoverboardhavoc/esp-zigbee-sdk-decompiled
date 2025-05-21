/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zdo_command.o -> zdo_mgmt_lqi_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_mgmt_lqi_cb(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte *unaff_s0;
  undefined4 uVar8;
  byte *unaff_s1;
  byte *pbVar9;
  int iVar10;
  byte *pbVar11;
  uint unaff_s3;
  code *pcVar12;
  uint __nmemb;
  byte bStack_28;
  byte bStack_27;
  byte bStack_26;
  byte bStack_25;
  byte *pbStack_24;
  
  if (param_1 == 0) {
    pbVar9 = (byte *)zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_zdo_command.c"
                               ,0x447);
  }
  else {
    unaff_s1 = (byte *)zb_buf_begin_func();
    unaff_s3 = (uint)*unaff_s1;
    unaff_s0 = (byte *)esp_zb_zdo_callback_find(unaff_s3);
    if ((unaff_s0 == (byte *)0x0) || (pbVar9 = unaff_s0, *unaff_s0 != unaff_s3)) goto _L0;
  }
  if (pbVar9[1] == 0x31) {
    zb_schedule_alarm_cancel(zdo_mgmt_lqi_req_timeout,unaff_s3,0);
    pcVar12 = *(code **)(unaff_s0 + 4);
    uVar8 = *(undefined4 *)(unaff_s0 + 8);
    if (pcVar12 != (code *)0x0) {
      bStack_28 = unaff_s1[1];
      bStack_27 = unaff_s1[2];
      bStack_25 = unaff_s1[4];
      __nmemb = (uint)bStack_25;
      bStack_26 = unaff_s1[3];
      pbStack_24 = (byte *)calloc(__nmemb,0x16);
      if (pbStack_24 == (byte *)0x0) {
        if (__nmemb != 0) {
          bStack_28 = 0x8a;
        }
      }
      else {
        pbVar11 = unaff_s1 + 5;
        pbVar9 = pbStack_24;
        for (iVar10 = 0; iVar10 < (int)(uint)bStack_25; iVar10 = iVar10 + 1) {
          bVar1 = pbVar11[1];
          bVar2 = pbVar11[2];
          bVar3 = pbVar11[3];
          bVar4 = pbVar11[4];
          bVar5 = pbVar11[5];
          bVar6 = pbVar11[6];
          bVar7 = pbVar11[7];
          *pbVar9 = *pbVar11;
          pbVar9[1] = bVar1;
          pbVar9[2] = bVar2;
          pbVar9[3] = bVar3;
          pbVar9[4] = bVar4;
          pbVar9[5] = bVar5;
          pbVar9[6] = bVar6;
          pbVar9[7] = bVar7;
          bVar1 = pbVar11[9];
          bVar2 = pbVar11[10];
          bVar3 = pbVar11[0xb];
          bVar4 = pbVar11[0xc];
          bVar5 = pbVar11[0xd];
          bVar6 = pbVar11[0xe];
          bVar7 = pbVar11[0xf];
          pbVar9[8] = pbVar11[8];
          pbVar9[9] = bVar1;
          pbVar9[10] = bVar2;
          pbVar9[0xb] = bVar3;
          pbVar9[0xc] = bVar4;
          pbVar9[0xd] = bVar5;
          pbVar9[0xe] = bVar6;
          pbVar9[0xf] = bVar7;
          *(undefined2 *)(pbVar9 + 0x10) = *(undefined2 *)(pbVar11 + 0x10);
          pbVar9[0x14] = pbVar11[0x14];
          pbVar9[0x13] = pbVar11[0x13];
          pbVar9[0x15] = pbVar11[0x15];
          pbVar9[0x12] = pbVar9[0x12] & 0xfc | pbVar11[0x12] & 3;
          pbVar9[0x12] = (byte)((pbVar11[0x12] >> 2 & 3) << 2) | pbVar9[0x12] & 0xf3;
          bVar1 = pbVar9[0x12];
          bVar2 = (byte)(((int)(uint)pbVar11[0x12] >> 4 & 7U) << 4);
          pbVar9[0x12] = bVar2 | bVar1 & 0x8f;
          pbVar9[0x12] = bVar2 | bVar1 & 0xf;
          pbVar9 = pbVar9 + 0x16;
          pbVar11 = pbVar11 + 0x16;
        }
      }
      (*pcVar12)(&bStack_28,uVar8);
      if (pbStack_24 != (byte *)0x0) {
        free(pbStack_24);
      }
    }
  }
_L0:
  zb_buf_free_func(param_1);
  esp_zb_zdo_callback_remove(unaff_s3);
  return;
}

