/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_touchlink.o -> esp_zb_touchlink_send_ep_info_cmd_req
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
    uVar9 = DAT_000150c7;
    uVar8 = DAT_000150c6;
    uVar7 = DAT_000150c5;
    uVar6 = DAT_000150c4;
    uVar5 = DAT_000150c3;
    uVar4 = DAT_000150c2;
    uVar3 = DAT_000150c1;
    puVar11[3] = DAT_000150c0;
    puVar11[4] = uVar3;
    puVar11[5] = uVar4;
    puVar11[6] = uVar5;
    puVar11[7] = uVar6;
    puVar11[8] = uVar7;
    puVar11[9] = uVar8;
    puVar11[10] = uVar9;
    uVar2 = _DAT_000150bc;
    uStack_12 = (undefined1)_DAT_000150bc;
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

