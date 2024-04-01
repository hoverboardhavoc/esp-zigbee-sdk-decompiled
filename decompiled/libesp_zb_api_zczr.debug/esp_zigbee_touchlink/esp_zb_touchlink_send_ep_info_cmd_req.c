/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_touchlink.o -> esp_zb_touchlink_send_ep_info_cmd_req
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
    esp_log_write(1,"ESP_ZIGBEE_TOUCHLINK",&_LC1,uVar13,"ESP_ZIGBEE_TOUCHLINK",
                  "esp_zb_touchlink_send_ep_info_cmd_req",0x7e);
  }
  else {
    puVar11 = (undefined1 *)zb_buf_reuse_func();
    *puVar11 = 9;
    pcVar12 = (char *)zb_zcl_get_ctx();
    cVar1 = *pcVar12;
    *pcVar12 = cVar1 + '\x01';
    puVar11[1] = cVar1;
    puVar11[2] = 0x40;
    uVar9 = DAT_0001131f;
    uVar8 = DAT_0001131e;
    uVar7 = DAT_0001131d;
    uVar6 = DAT_0001131c;
    uVar5 = DAT_0001131b;
    uVar4 = DAT_0001131a;
    uVar3 = DAT_00011319;
    puVar11[3] = DAT_00011318;
    puVar11[4] = uVar3;
    puVar11[5] = uVar4;
    puVar11[6] = uVar5;
    puVar11[7] = uVar6;
    puVar11[8] = uVar7;
    puVar11[9] = uVar8;
    puVar11[10] = uVar9;
    uVar2 = _DAT_00011314;
    uStack_12 = (undefined1)_DAT_00011314;
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

