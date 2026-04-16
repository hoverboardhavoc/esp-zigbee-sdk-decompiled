/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> check_read_reporting_configuration_field
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t
check_read_reporting_configuration_field
          (zcl_read_reporting_configuration_req_t *req,zcl_attr_desc_t *attr_desc)

{
  zcl_status_t zVar1;
  
  if (attr_desc == (zcl_attr_desc_t *)0x0) {
    zVar1 = 0x86;
  }
  else if (attr_desc->data_p == (void *)0x0) {
    zVar1 = 0x86;
  }
  else if ((attr_desc->access & 4) == 0) {
    zVar1 = 0x8c;
  }
  else {
    zVar1 = '\0';
  }
  if (req != (zcl_read_reporting_configuration_req_t *)0x0) {
    if (req->direction < 2) {
      return zVar1;
    }
    return 0x87;
  }
  return 0x87;
}

