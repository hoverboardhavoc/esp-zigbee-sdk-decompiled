/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_device_attribute_update_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_device_attribute_update_handler(void)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  undefined4 uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  
  iVar3 = zb_buf_get_tail_func(0x38);
  uStack_34 = 0;
  uStack_30 = CONCAT31(uStack_30._1_3_,*(undefined1 *)(iVar3 + 4));
  uVar2 = *(undefined2 *)(iVar3 + 0xc);
  uStack_30 = CONCAT22(uVar2,(undefined2)uStack_30);
  uStack_2c = (uint)*(ushort *)(iVar3 + 0xe);
  uStack_28 = 0;
  uStack_24 = uStack_24 & 0xff000000;
  iVar4 = find_device_endpoint_cluster_attribute(uVar2,*(ushort *)(iVar3 + 0xe));
  if (iVar4 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar5,"ESP_ZIGBEE_CORE",
                  "zcl_device_attribute_update_handler",0x17e,uVar2);
    return 0xffffffe4;
  }
  bVar1 = *(byte *)(iVar4 + 2);
  uStack_2c = (uint)CONCAT12(bVar1,(undefined2)uStack_2c);
  uStack_28 = uStack_28 & 0xffff0000;
  if (bVar1 != 0x22) {
    if (0x22 < bVar1) {
      if (bVar1 < 0x43) {
        if (bVar1 < 0x41) {
          if (bVar1 == 0x2a) goto _L0;
          if (bVar1 < 0x2b) {
            if (bVar1 == 0x25) goto _L0;
            if (bVar1 < 0x26) {
              if (bVar1 == 0x23) goto _L0;
            }
            else {
              if (bVar1 == 0x28) goto _L0;
              if (bVar1 == 0x29) goto _L0;
            }
          }
          else {
            if (bVar1 == 0x2d) {
_L0:
              uStack_28 = CONCAT13((char)(iVar3 + 0x10),0x80000);
              uStack_24._0_3_ = (undefined3)((uint)(iVar3 + 0x10) >> 8);
              goto _L0;
            }
            if (bVar1 < 0x2e) {
              if (bVar1 == 0x2b) goto _L0;
            }
            else {
              if (bVar1 == 0x30) goto _L0;
              if (bVar1 == 0x31) goto _L0;
            }
          }
_L0:
          uStack_34 = 1;
          uVar5 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC4,uVar5,"ESP_ZIGBEE_CORE",*(undefined1 *)(iVar4 + 2)
                       );
          goto _L0;
        }
      }
      else {
        if (bVar1 == 0xf0) {
          uStack_28 = CONCAT13((char)(iVar3 + 0x10),0x80000);
          uStack_24._0_3_ = (undefined3)((uint)(iVar3 + 0x10) >> 8);
          goto _L0;
        }
        if ((0xf0 < bVar1) || ((bVar1 != 0x48 && (bVar1 != 0xe2)))) goto _L0;
      }
      uStack_28 = (uint)CONCAT11((char)*(undefined4 *)(iVar3 + 0x14),*(undefined1 *)(iVar3 + 0x10))
                  << 0x10;
      uStack_24._0_3_ = (undefined3)((uint)*(undefined4 *)(iVar3 + 0x14) >> 8);
      goto _L0;
    }
    if (bVar1 == 0xd) goto _L0;
    if (0xd < bVar1) {
      if (bVar1 == 0x1b) {
_L0:
        uStack_28 = CONCAT13((char)(iVar3 + 0x10),0x40000);
        uStack_24._0_3_ = (undefined3)((uint)(iVar3 + 0x10) >> 8);
        goto _L0;
      }
      if (bVar1 < 0x1c) {
        if (bVar1 == 0x19) {
_L0:
          uStack_28 = CONCAT13((char)(iVar3 + 0x10),0x20000);
          uStack_24._0_3_ = (undefined3)((uint)(iVar3 + 0x10) >> 8);
          goto _L0;
        }
        if (bVar1 < 0x1a) {
          if ((bVar1 == 0x10) || (bVar1 == 0x18)) goto _L0;
        }
        else if (bVar1 == 0x1a) goto _L0;
      }
      else {
        if (bVar1 == 0x20) {
_L0:
          uStack_28 = CONCAT13((char)(iVar3 + 0x10),0x10000);
          uStack_24._0_3_ = (undefined3)((uint)(iVar3 + 0x10) >> 8);
          goto _L0;
        }
        if (bVar1 == 0x21) goto _L0;
        if (bVar1 == 0x1d) goto _L0;
      }
      goto _L0;
    }
    if (bVar1 == 0) goto _L0;
    if (bVar1 != 10) {
      if (bVar1 < 0xb) {
        if (bVar1 == 8) goto _L0;
        if (bVar1 == 9) goto _L0;
      }
      else if (bVar1 == 0xb) goto _L0;
      goto _L0;
    }
  }
_L0:
  uStack_28 = CONCAT13((char)(iVar3 + 0x10),0x40000);
  uStack_24._0_3_ = (undefined3)((uint)(iVar3 + 0x10) >> 8);
_L0:
  if (zcl_set_attr_user_cb == (code *)0x0) {
    uVar5 = 0;
  }
  else {
    uStack_60 = uStack_34;
    uStack_5c = uStack_30;
    uStack_58 = uStack_2c;
    uStack_54 = uStack_28;
    uStack_50 = uStack_24;
    (*zcl_set_attr_user_cb)(&uStack_60);
    uVar5 = error_to_zb_ret();
  }
  return uVar5;
}

