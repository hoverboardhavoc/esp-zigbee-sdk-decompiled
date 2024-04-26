/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_commissioning_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_commissioning_cluster_add_attr(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0x13) {
    uVar1 = esp_zb_cluster_add_attr(0x15,0x13,0x10,3,param_2);
    return uVar1;
  }
  if (param_1 < 0x14) {
    if (param_1 == 5) {
      uVar1 = esp_zb_cluster_add_attr(0x15,5,0x20,3);
      return uVar1;
    }
    if (param_1 < 6) {
      if (param_1 == 2) {
        uVar1 = esp_zb_cluster_add_attr(0x15,2,0x21,3);
        return uVar1;
      }
      if (param_1 < 3) {
        if (param_1 == 0) {
          uVar1 = esp_zb_cluster_add_attr(0x15,0,0x21,3);
          return uVar1;
        }
        if (param_1 == 1) {
          uVar1 = esp_zb_cluster_add_attr(0x15,1,0xf0,3);
          return uVar1;
        }
      }
      else {
        if (param_1 == 3) {
          uVar1 = esp_zb_cluster_add_attr(0x15,3,0x1b,3);
          return uVar1;
        }
        if (param_1 == 4) {
          uVar1 = esp_zb_cluster_add_attr(0x15,4,0x20,3);
          return uVar1;
        }
      }
    }
    else {
      if (param_1 == 0x11) {
        uVar1 = esp_zb_cluster_add_attr(0x15,0x11,0xf1,3);
        return uVar1;
      }
      if (param_1 < 0x12) {
        if (param_1 == 6) {
          uVar1 = esp_zb_cluster_add_attr(0x15,6,0x30,3);
          return uVar1;
        }
        if (param_1 == 0x10) {
          uVar1 = esp_zb_cluster_add_attr(0x15,0x10,0xf0,3);
          return uVar1;
        }
      }
      else if (param_1 == 0x12) {
        uVar1 = esp_zb_cluster_add_attr(0x15,0x12,0xf1,3);
        return uVar1;
      }
    }
  }
  else {
    if (param_1 == 0x20) {
      uVar1 = esp_zb_cluster_add_attr(0x15,0x20,0x20,3);
      return uVar1;
    }
    if (param_1 < 0x21) {
      if (param_1 == 0x16) {
        uVar1 = esp_zb_cluster_add_attr(0x15,0x16,0x30,3);
        return uVar1;
      }
      if (param_1 < 0x17) {
        if (param_1 == 0x14) {
          uVar1 = esp_zb_cluster_add_attr(0x15,0x14,0xf1,3);
          return uVar1;
        }
        if (param_1 == 0x15) {
          uVar1 = esp_zb_cluster_add_attr(0x15,0x15,0x20,3);
          return uVar1;
        }
      }
      else if (param_1 == 0x17) {
        uVar1 = esp_zb_cluster_add_attr(0x15,0x17,0x21,3);
        return uVar1;
      }
    }
    else {
      if (param_1 == 0x41) {
        uVar1 = esp_zb_cluster_add_attr(0x15,0x41,0x20,3);
        return uVar1;
      }
      if (param_1 < 0x42) {
        if (param_1 == 0x21) {
          uVar1 = esp_zb_cluster_add_attr(0x15,0x21,0x21,3);
          return uVar1;
        }
        if (param_1 == 0x40) {
          uVar1 = esp_zb_cluster_add_attr(0x15,0x40,0x10,3);
          return uVar1;
        }
      }
      else if (param_1 == 0x42) {
        uVar1 = esp_zb_cluster_add_attr(0x15,0x42,0x20,3);
        return uVar1;
      }
    }
  }
  uVar1 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_L0,uVar1,0x10000);
  return 0x102;
}

