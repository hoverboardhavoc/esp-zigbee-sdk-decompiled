/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_ota_upgrade.o -> zcl_ota_upgrade_srv_query_image_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_ota_upgrade_srv_query_image_handler(void)

{
  int iVar1;
  byte bVar2;
  uint local_30;
  ushort uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  local_30 = (uint)(iVar1 == 0);
  uStack_28 = 0;
  uStack_24 = 0;
  bVar2 = 0xff;
  if (iVar1 != 0) {
    bVar2 = *(byte *)(iVar1 + 4);
  }
  _uStack_2c = CONCAT22(0x19,(ushort)bVar2);
  iStack_20 = (uint)*(ushort *)(iVar1 + 0x2b) << 0x10;
  uStack_1c = (uint)*(ushort *)(iVar1 + 0x2d);
  uStack_18 = *(undefined4 *)(iVar1 + 0x2f);
  uStack_14 = *(undefined4 *)(iVar1 + 0x33);
  memcpy(&uStack_28,*(void **)(iVar1 + 0x27),9);
  esp_zb_core_action_handler_schedule(6,&local_30);
  esp_err_to_zb_ret();
  return;
}

