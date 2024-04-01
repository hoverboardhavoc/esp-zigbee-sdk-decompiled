/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ota.o -> esp_zb_ota_upgrade_server_notify_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ota_upgrade_server_notify_req(undefined1 *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  
  iVar2 = zb_zcl_get_ctx();
  if (*(int *)(iVar2 + 0xb8) == 0) {
    zb_zcl_ota_upgrade_init_server(*param_1,0x10000);
  }
  iVar2 = zb_zcl_get_attr_desc_a(*param_1,0x19,1,0xfff0);
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    s_ota_server_variable = *(int *)(iVar2 + 6);
    if (s_ota_server_variable == 0) {
      uVar3 = 0x105;
    }
    else {
      if ((byte)param_1[1] < *(byte *)(s_ota_server_variable + 8)) {
        puVar4 = (undefined4 *)malloc(0x38);
        iVar2 = *(int *)(param_1 + 0x14);
        if (iVar2 != 0) {
          *puVar4 = 0xbeef11e;
          puVar4[1] = 0x380100;
          *(undefined2 *)(puVar4 + 2) = 0x10;
          *(undefined2 *)((int)puVar4 + 10) = *(undefined2 *)(param_1 + 8);
          *(undefined2 *)(puVar4 + 3) = *(undefined2 *)(param_1 + 10);
          uVar3 = *(undefined4 *)(param_1 + 0xc);
          *(short *)((int)puVar4 + 0xe) = (short)uVar3;
          *(short *)(puVar4 + 4) = (short)((uint)uVar3 >> 0x10);
          *(undefined2 *)((int)puVar4 + 0x12) = 2;
          memset(puVar4 + 5,0,0x20);
          puVar4[0xd] = *(int *)(param_1 + 0x10) + 0x38;
          s_ota_next_data_cb = iVar2;
          iVar2 = zb_buf_get_out_func();
          if (iVar2 == 0) {
            __assert_func(0,0,0);
          }
          puVar5 = (undefined1 *)zb_buf_get_tail_func(0x10);
          *puVar5 = *param_1;
          uVar1 = param_1[1];
          *(undefined4 **)(puVar5 + 4) = puVar4;
          puVar5[1] = uVar1;
          *(undefined4 *)(puVar5 + 0xc) = *(undefined4 *)(param_1 + 4);
          puVar5[8] = param_1[2];
          iVar2 = zb_zcl_ota_upgrade_insert_file(iVar2);
          if (iVar2 == 0) {
            return 0;
          }
        }
      }
      uVar3 = 0x102;
    }
  }
  return uVar3;
}

