/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> convert_esp_config_report_record_to_ezb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void convert_esp_config_report_record_to_ezb
               (ezb_zcl_config_report_record_t *dst,esp_zb_zcl_config_report_record_t *src)

{
  int iVar1;
  size_t __n;
  
  memset(dst,0,0x18);
  dst->direction = src->direction;
  dst->attr_id = src->attributeID;
  if (src->direction == '\0') {
    (dst->field_2).client.attr_type = (src->field_2).field_0.attrType;
    (dst->field_2).client.min_interval = (src->field_2).field_0.min_interval;
    (dst->field_2).client.max_interval = (src->field_2).field_0.max_interval;
    if ((((src->field_2).field_0.reportable_change != (void *)0x0) &&
        (iVar1 = ezb_zcl_attr_type_is_analog((src->field_2).field_0.attrType), iVar1 != 0)) &&
       (__n = ezb_zcl_get_attr_value_size
                        ((src->field_2).field_0.attrType,(src->field_2).field_0.reportable_change),
       (__n - 1 & 0xffff) < 8)) {
      memcpy((void *)((int)&dst->field_2 + 8),(src->field_2).field_0.reportable_change,__n);
    }
  }
  else {
    (dst->field_2).server.timeout = (src->field_2).field_1.timeout;
  }
  return;
}

