/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_internal_zcl_clone_attribute
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_internal_zcl_clone_attribute(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  size_t __size;
  undefined4 uVar10;
  void *__dest;
  
  if ((param_1 == (undefined1 *)0x0) || (param_2 == (undefined1 *)0x0)) {
    uVar10 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC2,uVar10,0x10000,"esp_zb_internal_zcl_clone_attribute",0x57,
                  "esp_zb_internal_zcl_clone_attribute");
    uVar10 = 0x102;
  }
  else {
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    uVar3 = param_2[3];
    uVar4 = param_2[4];
    uVar5 = param_2[5];
    uVar6 = param_2[6];
    uVar7 = param_2[7];
    uVar8 = param_2[8];
    uVar9 = param_2[9];
    *param_1 = *param_2;
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    param_1[3] = uVar3;
    param_1[4] = uVar4;
    param_1[5] = uVar5;
    param_1[6] = uVar6;
    param_1[7] = uVar7;
    param_1[8] = uVar8;
    param_1[9] = uVar9;
    if ((param_2[3] & 0x40) == 0) {
      __size = esp_zb_zcl_get_attribute_size(param_2[2],*(undefined4 *)(param_2 + 6));
    }
    else {
      __size = (size_t)(byte)param_2[2];
    }
    if (__size == 0) {
      param_1[6] = 0;
      param_1[7] = 0;
      param_1[8] = 0;
      param_1[9] = 0;
      uVar10 = 0;
    }
    else {
      __dest = malloc(__size);
      param_1[6] = (char)__dest;
      param_1[7] = (char)((uint)__dest >> 8);
      param_1[8] = (char)((uint)__dest >> 0x10);
      param_1[9] = (char)((uint)__dest >> 0x18);
      if (__dest == (void *)0x0) {
        uVar10 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC3,uVar10,0x10000,"esp_zb_internal_zcl_clone_attribute",99);
        uVar10 = 0x101;
      }
      else if ((param_2[3] & 0x40) == 0) {
        esp_zb_zcl_put_attribute_value(param_2[2],*(undefined4 *)(param_2 + 6),__size);
        uVar10 = 0;
      }
      else {
        memcpy(__dest,*(void **)(param_2 + 6),__size);
        uVar10 = 0;
      }
    }
  }
  return uVar10;
}

