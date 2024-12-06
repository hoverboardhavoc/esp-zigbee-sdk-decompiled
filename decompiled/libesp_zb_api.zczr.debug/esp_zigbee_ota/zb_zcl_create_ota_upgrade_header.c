/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_ota.o -> zb_zcl_create_ota_upgrade_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * zb_zcl_create_ota_upgrade_header(undefined2 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  ushort uVar8;
  undefined2 uVar9;
  size_t __size;
  undefined1 *puVar10;
  int iVar11;
  undefined4 uVar12;
  undefined1 *puVar13;
  
  if (param_1 == (undefined2 *)0x0) {
    uVar12 = esp_log_timestamp();
    esp_log_write(1,0x100c4,&_LC6,uVar12,0x100c4,"zb_zcl_create_ota_upgrade_header",0x8d);
    puVar10 = (undefined1 *)0x0;
  }
  else {
    __size = zb_zcl_get_ota_upgrade_header_size(param_1[6]);
    puVar10 = (undefined1 *)malloc(__size);
    if (puVar10 == (undefined1 *)0x0) {
      uVar12 = esp_log_timestamp();
      esp_log_write(1,0x100c4,&_LC7,uVar12,0x100c4,"zb_zcl_create_ota_upgrade_header",0x90);
    }
    else {
      *puVar10 = 0x1e;
      puVar10[1] = 0xf1;
      puVar10[2] = 0xee;
      puVar10[3] = 0xb;
      puVar10[4] = 0;
      puVar10[5] = 1;
      puVar10[0x12] = 2;
      puVar10[0x13] = 0;
      memset(puVar10 + 0x14,0,0x20);
      puVar10[6] = (char)__size;
      puVar10[7] = (char)(__size >> 8);
      uVar8 = param_1[6];
      puVar10[8] = (char)uVar8;
      puVar10[9] = (char)(uVar8 >> 8);
      uVar9 = *param_1;
      puVar10[10] = (char)uVar9;
      puVar10[0xb] = (char)((ushort)uVar9 >> 8);
      uVar9 = param_1[1];
      puVar10[0xc] = (char)uVar9;
      puVar10[0xd] = (char)((ushort)uVar9 >> 8);
      uVar12 = *(undefined4 *)(param_1 + 2);
      puVar10[0xe] = (char)uVar12;
      puVar10[0xf] = (char)((uint)uVar12 >> 8);
      puVar10[0x10] = (char)((uint)uVar12 >> 0x10);
      puVar10[0x11] = (char)((uint)uVar12 >> 0x18);
      iVar11 = __size + *(int *)(param_1 + 4);
      puVar10[0x34] = (char)iVar11;
      puVar10[0x35] = (char)((uint)iVar11 >> 8);
      puVar10[0x36] = (char)((uint)iVar11 >> 0x10);
      puVar10[0x37] = (char)((uint)iVar11 >> 0x18);
      iVar11 = 0x38;
      if ((uVar8 & 1) != 0) {
        puVar10[0x38] = *(undefined1 *)(param_1 + 7);
        iVar11 = 0x39;
      }
      puVar13 = puVar10 + iVar11;
      if ((uVar8 & 2) != 0) {
        uVar1 = *(undefined1 *)(param_1 + 8);
        uVar2 = *(undefined1 *)((int)param_1 + 0x11);
        uVar3 = *(undefined1 *)(param_1 + 9);
        uVar4 = *(undefined1 *)((int)param_1 + 0x13);
        uVar5 = *(undefined1 *)(param_1 + 10);
        uVar6 = *(undefined1 *)((int)param_1 + 0x15);
        uVar7 = *(undefined1 *)(param_1 + 0xb);
        *puVar13 = *(undefined1 *)((int)param_1 + 0xf);
        puVar13[1] = uVar1;
        puVar13[2] = uVar2;
        puVar13[3] = uVar3;
        puVar13[4] = uVar4;
        puVar13[5] = uVar5;
        puVar13[6] = uVar6;
        puVar13[7] = uVar7;
        puVar13 = puVar13 + 8;
      }
      if ((puVar10[8] & 4) != 0) {
        *puVar13 = *(undefined1 *)(param_1 + 0xc);
        puVar13[1] = *(undefined1 *)((int)param_1 + 0x19);
        puVar13[2] = *(undefined1 *)(param_1 + 0xd);
        puVar13[3] = *(undefined1 *)((int)param_1 + 0x1b);
      }
    }
  }
  return puVar10;
}

