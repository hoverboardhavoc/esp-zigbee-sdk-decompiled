/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_test_utils.o -> esp_zb_apsme_remove_device_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_apsme_remove_device_request(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  
  iVar8 = zb_buf_get_out_func();
  if (iVar8 == 0) {
    uVar10 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar10,0x10000,"esp_zb_apsme_remove_device_request",0x3a);
    uVar10 = 0x101;
  }
  else {
    puVar9 = (undefined1 *)zb_buf_get_tail_func(0x10);
    uVar1 = param_1[1];
    uVar2 = param_1[2];
    uVar3 = param_1[3];
    uVar4 = param_1[4];
    uVar5 = param_1[5];
    uVar6 = param_1[6];
    uVar7 = param_1[7];
    *puVar9 = *param_1;
    puVar9[1] = uVar1;
    puVar9[2] = uVar2;
    puVar9[3] = uVar3;
    puVar9[4] = uVar4;
    puVar9[5] = uVar5;
    puVar9[6] = uVar6;
    puVar9[7] = uVar7;
    uVar1 = param_1[9];
    uVar2 = param_1[10];
    uVar3 = param_1[0xb];
    uVar4 = param_1[0xc];
    uVar5 = param_1[0xd];
    uVar6 = param_1[0xe];
    uVar7 = param_1[0xf];
    puVar9[8] = param_1[8];
    puVar9[9] = uVar1;
    puVar9[10] = uVar2;
    puVar9[0xb] = uVar3;
    puVar9[0xc] = uVar4;
    puVar9[0xd] = uVar5;
    puVar9[0xe] = uVar6;
    puVar9[0xf] = uVar7;
    zb_schedule_callback(&zb_secur_apsme_remove_device,iVar8);
    uVar10 = 0;
  }
  return uVar10;
}

