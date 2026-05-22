/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> simple_measurement.o -> ezb_zcl_ec_measurement_cluster_client_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_ec_measurement_cluster_client_init(uint8_t ep_id)

{
  int iVar1;
  undefined4 uStack_24;
  zcl_cluster_template_t template;
  
  uStack_24 = 0x2040a;
  template.cluster_id = 0;
  template.cluster_role = '\0';
  template._3_1_ = 0;
  template.check_value_handler = (zcl_cluster_check_value_t)0x0;
  template.write_attr_handler = (zcl_cluster_write_attr_t)0x0;
  template.cmd_disc_handler = (zcl_cluster_disc_cmd_t)0x0;
  iVar1 = zcl_cluster_template_add(&uStack_24);
  if (iVar1 == 0) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/simple_measurement.c",
                0x1ff,"ezb_zcl_ec_measurement_cluster_client_init",
                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  return;
}

