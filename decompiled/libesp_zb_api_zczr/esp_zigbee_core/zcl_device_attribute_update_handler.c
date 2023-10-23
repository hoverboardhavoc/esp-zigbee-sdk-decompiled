/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_device_attribute_update_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_device_attribute_update_handler(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uStack_24;
  undefined1 uStack_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  ushort uStack_1a;
  undefined2 uStack_18;
  undefined1 uStack_16;
  undefined1 uStack_15;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  uStack_24 = 0;
  uStack_20 = *(undefined1 *)(iVar2 + 4);
  uStack_1e = *(undefined2 *)(iVar2 + 0xc);
  uStack_1c = *(undefined2 *)(iVar2 + 0xe);
  uStack_1a = 0;
  uStack_18 = 0;
  uStack_16 = 0;
  uStack_15 = 0;
  uStack_14 = 0;
  uStack_13 = 0;
  uStack_12 = 0;
  iVar3 = find_device_endpoint_cluster_attribute();
  if (iVar3 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE",
                  "zcl_device_attribute_update_handler",0x18e,uStack_1e);
    return 0xffffffe4;
  }
  uStack_1a = (ushort)*(byte *)(iVar3 + 2);
  uStack_18 = 0;
  bVar1 = *(byte *)(iVar3 + 2);
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
              uStack_16 = 8;
              iVar2 = iVar2 + 0x10;
              uStack_15 = (undefined1)iVar2;
              uStack_14 = (undefined1)((uint)iVar2 >> 8);
              uStack_13 = (undefined1)((uint)iVar2 >> 0x10);
              uStack_12 = (undefined1)((uint)iVar2 >> 0x18);
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
          uStack_24 = 1;
          uVar4 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC5,uVar4,"ESP_ZIGBEE_CORE",*(undefined1 *)(iVar3 + 2)
                       );
          goto _L0;
        }
      }
      else {
        if (bVar1 == 0xf0) {
          uStack_16 = 8;
          iVar2 = iVar2 + 0x10;
          uStack_15 = (undefined1)iVar2;
          uStack_14 = (undefined1)((uint)iVar2 >> 8);
          uStack_13 = (undefined1)((uint)iVar2 >> 0x10);
          uStack_12 = (undefined1)((uint)iVar2 >> 0x18);
          goto _L0;
        }
        if ((0xf0 < bVar1) || ((bVar1 != 0x48 && (bVar1 != 0xe2)))) goto _L0;
      }
      uStack_16 = *(undefined1 *)(iVar2 + 0x10);
      uVar4 = *(undefined4 *)(iVar2 + 0x14);
      uStack_15 = (undefined1)uVar4;
      uStack_14 = (undefined1)((uint)uVar4 >> 8);
      uStack_13 = (undefined1)((uint)uVar4 >> 0x10);
      uStack_12 = (undefined1)((uint)uVar4 >> 0x18);
      goto _L0;
    }
    if (bVar1 == 0xd) goto _L0;
    if (0xd < bVar1) {
      if (bVar1 == 0x1b) {
_L0:
        uStack_16 = 4;
        iVar2 = iVar2 + 0x10;
        uStack_15 = (undefined1)iVar2;
        uStack_14 = (undefined1)((uint)iVar2 >> 8);
        uStack_13 = (undefined1)((uint)iVar2 >> 0x10);
        uStack_12 = (undefined1)((uint)iVar2 >> 0x18);
        goto _L0;
      }
      if (bVar1 < 0x1c) {
        if (bVar1 == 0x19) {
_L0:
          uStack_16 = 2;
          iVar2 = iVar2 + 0x10;
          uStack_15 = (undefined1)iVar2;
          uStack_14 = (undefined1)((uint)iVar2 >> 8);
          uStack_13 = (undefined1)((uint)iVar2 >> 0x10);
          uStack_12 = (undefined1)((uint)iVar2 >> 0x18);
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
          uStack_16 = 1;
          iVar2 = iVar2 + 0x10;
          uStack_15 = (undefined1)iVar2;
          uStack_14 = (undefined1)((uint)iVar2 >> 8);
          uStack_13 = (undefined1)((uint)iVar2 >> 0x10);
          uStack_12 = (undefined1)((uint)iVar2 >> 0x18);
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
  uStack_16 = 4;
  iVar2 = iVar2 + 0x10;
  uStack_15 = (undefined1)iVar2;
  uStack_14 = (undefined1)((uint)iVar2 >> 8);
  uStack_13 = (undefined1)((uint)iVar2 >> 0x10);
  uStack_12 = (undefined1)((uint)iVar2 >> 0x18);
_L0:
  if (zb_core_action_cb == (code *)0x0) {
    uVar4 = 0;
  }
  else {
    (*zb_core_action_cb)(0,&uStack_24);
    uVar4 = error_to_zb_ret();
  }
  return uVar4;
}

