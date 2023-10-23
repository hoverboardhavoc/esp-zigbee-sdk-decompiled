/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_ota_upgrade_srv_status_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ota_upgrade_srv_status_handler(undefined4 param_1)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  undefined4 uVar4;
  byte bVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uStack_34;
  ushort uStack_30;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  puVar2 = (uint *)zb_buf_get_tail_func(param_1,0x38);
  if (*puVar2 < 0x25) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE",
                  "zcl_ota_upgrade_srv_status_handler",0x409);
    uVar4 = 0xffffffff;
  }
  else {
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    iStack_20 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    uStack_34 = (uint)(iVar1 == 0);
    if (iVar1 == 0) {
      bVar5 = 0xff;
    }
    else {
      bVar5 = *(byte *)(iVar1 + 4);
    }
    _uStack_30 = CONCAT22(0x19,(ushort)bVar5);
    piVar3 = (int *)zb_buf_get_tail_func(param_1,0x38);
    iStack_20 = *piVar3 + -0x25;
    piVar3 = (int *)zb_buf_get_tail_func(param_1,0x38);
    iVar6 = *piVar3;
    if (iVar6 == 0x26) {
      uStack_1c = CONCAT22(uStack_1c._2_2_,*(undefined2 *)(iVar1 + 0x10));
      uStack_18 = *(uint *)(iVar1 + 0x12);
      puVar7 = *(undefined4 **)(iVar1 + 0xc);
      uStack_2c = *puVar7;
      uStack_28 = puVar7[1];
      uStack_24 = CONCAT31(uStack_24._1_3_,*(undefined1 *)(puVar7 + 2));
    }
    else if (iVar6 == 0x27) {
      uStack_34 = (uint)*(byte *)(iVar1 + 0x14);
      uStack_1c = CONCAT22(uStack_1c._2_2_,(short)((uint)*(undefined4 *)(iVar1 + 0x14) >> 8));
      uStack_18 = *(int *)(iVar1 + 0x18) << 8 | (uint)*(byte *)(iVar1 + 0x17);
      uStack_14 = *(undefined4 *)(iVar1 + 0x10);
      puVar7 = *(undefined4 **)(iVar1 + 0xc);
      uStack_2c = *puVar7;
      uStack_28 = puVar7[1];
      uStack_24 = CONCAT31(uStack_24._1_3_,*(undefined1 *)(puVar7 + 2));
    }
    else if (iVar6 == 0x25) {
      uStack_1c = CONCAT22(uStack_1c._2_2_,*(undefined2 *)(iVar1 + 0x10));
      uStack_18 = *(uint *)(iVar1 + 0x12);
      puVar7 = *(undefined4 **)(iVar1 + 0xc);
      uStack_2c = *puVar7;
      uStack_28 = puVar7[1];
      uStack_24 = CONCAT31(uStack_24._1_3_,*(undefined1 *)(puVar7 + 2));
    }
    if (zb_core_action_cb == (code *)0x0) {
      uVar4 = 0;
    }
    else {
      (*zb_core_action_cb)(5,&uStack_34);
      uVar4 = error_to_zb_ret();
    }
  }
  return uVar4;
}

