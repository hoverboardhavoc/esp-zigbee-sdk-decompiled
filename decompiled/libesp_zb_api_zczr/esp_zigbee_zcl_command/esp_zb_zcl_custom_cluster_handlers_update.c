/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_custom_cluster_handlers_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_zcl_custom_cluster_handlers_update(short *param_1)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 2);
  iVar6 = *(int *)(param_1 + 4);
  if (iVar7 == 0) {
    iVar4 = 0x102;
  }
  else {
    iVar4 = 0x102;
    if (iVar6 != 0) {
      sVar1 = *param_1;
      sVar2 = param_1[1];
      iVar5 = zb_zcl_get_ctx(0x102);
      iVar4 = 0x101;
      uVar3 = 0;
      if (*(byte *)(iVar5 + 0x23c) < 0x14) {
        while( true ) {
          iVar4 = zb_zcl_get_ctx(iVar4);
          if (*(byte *)(iVar4 + 0x23c) <= uVar3) break;
          iVar4 = zb_zcl_get_ctx();
          iVar5 = (uVar3 + 0xf) * 0x10;
          iVar4 = iVar4 + iVar5;
          if (*(short *)(iVar4 + 0xc) == sVar1) {
            iVar4 = zb_zcl_get_ctx();
            iVar4 = iVar4 + iVar5;
            if (*(char *)(iVar4 + 0xe) == (char)sVar2) {
              iVar4 = zb_zcl_get_ctx();
              *(int *)(iVar4 + iVar5 + 0x14) = iVar7;
              iVar4 = zb_zcl_get_ctx();
              iVar4 = iVar4 + iVar5;
              *(int *)(iVar4 + 0x18) = iVar6;
            }
          }
          uVar3 = uVar3 + 1 & 0xff;
        }
        iVar4 = zb_zcl_get_ctx();
        if (*(byte *)(iVar4 + 0x23c) == uVar3) {
          iVar4 = (uVar3 + 0xf) * 0x10;
          iVar5 = zb_zcl_get_ctx();
          *(short *)(iVar5 + iVar4 + 0xc) = sVar1;
          iVar5 = zb_zcl_get_ctx();
          *(char *)(iVar5 + iVar4 + 0xe) = (char)sVar2;
          iVar5 = zb_zcl_get_ctx();
          *(undefined4 *)(iVar5 + iVar4 + 0x10) = 0;
          iVar5 = zb_zcl_get_ctx();
          *(int *)(iVar5 + iVar4 + 0x14) = iVar7;
          iVar7 = zb_zcl_get_ctx();
          *(int *)(iVar7 + iVar4 + 0x18) = iVar6;
          iVar6 = zb_zcl_get_ctx();
          *(char *)(iVar6 + 0x23c) = *(char *)(iVar6 + 0x23c) + '\x01';
        }
        iVar4 = 0;
      }
    }
  }
  return iVar4;
}

