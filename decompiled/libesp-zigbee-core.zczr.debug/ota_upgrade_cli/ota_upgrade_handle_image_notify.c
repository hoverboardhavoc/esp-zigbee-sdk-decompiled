/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_handle_image_notify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ota_upgrade_handle_image_notify
          (ota_upgrade_downloading_context_t *context,uint16_t short_addr,
          ota_upgrade_image_notify_t *payload)

{
  uint8_t uVar1;
  uint uVar2;
  undefined2 in_register_0000202e;
  uint32_t uVar3;
  uint32_t uVar4;
  uint32_t *puVar5;
  
  if ((context == (ota_upgrade_downloading_context_t *)0x0) ||
     (payload == (ota_upgrade_image_notify_t *)0x0)) {
    context = (ota_upgrade_downloading_context_t *)
              __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c"
                            ,0x1a9,"ota_upgrade_handle_image_notify","context && payload");
_L0:
    puVar5 = (context->attr).current_file_version;
    if (puVar5 == (uint32_t *)0x0) {
      uVar4 = 0xffffffff;
    }
    else {
      uVar4 = *puVar5;
    }
    puVar5 = (context->attr).downloaded_file_version;
    if (puVar5 == (uint32_t *)0x0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = *puVar5;
    }
    if (payload->file_version == uVar4) {
      return 0x96;
    }
    if (payload->file_version == uVar3) {
      return 0x96;
    }
_L0:
    if ((payload->image_type != *(context->attr).image_type) && (payload->image_type != 0xffff)) {
      return 0x96;
    }
  }
  else {
    if (CONCAT22(in_register_0000202e,short_addr) < 0xfff8) {
      uVar2 = nwk_get_short_address();
      if (uVar2 != CONCAT22(in_register_0000202e,short_addr)) {
        return 0x96;
      }
      goto _L0;
    }
    uVar1 = payload->type;
    if (uVar1 == '\x02') goto _L0;
    if (uVar1 == '\x03') goto _L0;
    if (uVar1 != '\x01') {
      return 0x96;
    }
  }
  if ((payload->manuf_code != *(context->attr).manuf_code) && (payload->manuf_code != 0xffff)) {
    return 0x96;
  }
_L0:
  uVar2 = random_noncrypto_get_u32();
  if ((uint)payload->query_jitter < uVar2 % 100) {
    return 0xfe;
  }
  return '\0';
}

