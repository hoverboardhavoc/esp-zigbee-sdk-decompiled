/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_touchlink.o -> esp_zb_touchlink_send_ep_info_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_zb_touchlink_send_ep_info_cmd_req(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  int iVar10;
  undefined1 *puVar11;
  char *pcVar12;
  undefined4 uVar13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  iVar10 = zb_buf_get_out_func();
  if (iVar10 == 0) {
    uVar13 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_TOUCHLINK","E (%lu) %s: %s(%d): Not memory for buffer id\n",uVar13,
            "ESP_ZIGBEE_TOUCHLINK","esp_zb_touchlink_send_ep_info_cmd_req",0x83);
  }
  else {
    puVar11 = (undefined1 *)zb_buf_reuse_func();
    *puVar11 = 9;
    pcVar12 = (char *)zb_zcl_get_ctx();
    cVar1 = *pcVar12;
    *pcVar12 = cVar1 + '\x01';
    puVar11[1] = cVar1;
    puVar11[2] = 0x40;
    uVar9 = DAT_00011317;
    uVar8 = DAT_00011316;
    uVar7 = DAT_00011315;
    uVar6 = DAT_00011314;
    uVar5 = DAT_00011313;
    uVar4 = DAT_00011312;
    uVar3 = DAT_00011311;
    puVar11[3] = DAT_00011310;
    puVar11[4] = uVar3;
    puVar11[5] = uVar4;
    puVar11[6] = uVar5;
    puVar11[7] = uVar6;
    puVar11[8] = uVar7;
    puVar11[9] = uVar8;
    puVar11[10] = uVar9;
    uVar2 = _DAT_0001130c;
    uStack_12 = (undefined1)_DAT_0001130c;
    puVar11[0xb] = uStack_12;
    uStack_11 = (undefined1)((ushort)uVar2 >> 8);
    puVar11[0xc] = uStack_11;
    puVar11[0xd] = *(undefined1 *)(param_1 + 10);
    uVar2 = *(undefined2 *)(param_1 + 0xc);
    uStack_12 = (undefined1)uVar2;
    puVar11[0xe] = uStack_12;
    uStack_11 = (undefined1)((ushort)uVar2 >> 8);
    puVar11[0xf] = uStack_11;
    uVar2 = *(undefined2 *)(param_1 + 0xe);
    uStack_12 = (undefined1)uVar2;
    puVar11[0x10] = uStack_12;
    uStack_11 = (undefined1)((ushort)uVar2 >> 8);
    puVar11[0x11] = uStack_11;
    puVar11[0x12] = *(undefined1 *)(param_1 + 0x10);
    zb_zcl_finish_and_send_packet
              (iVar10,puVar11 + 0x13,param_1,2,*(undefined1 *)(param_1 + 8),
               *(undefined1 *)(param_1 + 9),0xc05e,0x1000);
  }
  return;
}

