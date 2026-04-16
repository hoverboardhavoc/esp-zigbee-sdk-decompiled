/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_config_report_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t esp_zb_zcl_config_report_cmd_req(esp_zb_zcl_config_report_cmd_t *cmd_req)

{
  esp_zb_zcl_report_direction_t eVar1;
  ushort uVar2;
  uint16_t uVar3;
  esp_zb_zcl_config_report_record_t *peVar4;
  esp_zb_zcl_report_direction_t *__s;
  uint8_t uVar5;
  void *__ptr;
  int iVar6;
  size_t __n;
  uint uVar7;
  undefined1 auStack_44 [4];
  ezb_zcl_config_report_cmd_t req;
  
  memset(auStack_44,0,0x24);
  if (((cmd_req != (esp_zb_zcl_config_report_cmd_t *)0x0) && (cmd_req->record_number != 0)) &&
     (cmd_req->record_field != (esp_zb_zcl_config_report_record_t *)0x0)) {
    uVar7 = 0;
    __ptr = malloc((uint)cmd_req->record_number * 0x18);
    if (__ptr != (void *)0x0) {
      for (; uVar2 = cmd_req->record_number, uVar7 < uVar2; uVar7 = uVar7 + 1 & 0xffff) {
        peVar4 = cmd_req->record_field + uVar7;
        __s = (esp_zb_zcl_report_direction_t *)(uVar7 * 0x18 + (int)__ptr);
        memset(__s,0,0x18);
        eVar1 = peVar4->direction;
        *__s = eVar1;
        *(uint16_t *)(__s + 2) = peVar4->attributeID;
        if (eVar1 == '\0') {
          eVar1 = (peVar4->field_2).field_0.attrType;
          *(uint16_t *)(__s + 10) = (peVar4->field_2).field_0.min_interval;
          uVar3 = (peVar4->field_2).field_0.max_interval;
          __s[8] = eVar1;
          *(uint16_t *)(__s + 0xc) = uVar3;
          if ((((peVar4->field_2).field_0.reportable_change != (void *)0x0) &&
              (iVar6 = ezb_zcl_attr_type_is_analog(), iVar6 != 0)) &&
             (__n = ezb_zcl_get_attr_value_size
                              ((peVar4->field_2).field_0.attrType,
                               (peVar4->field_2).field_0.reportable_change), (__n - 1 & 0xffff) < 8)
             ) {
            memcpy(__s + 0x10,(peVar4->field_2).field_0.reportable_change,__n);
          }
        }
        else {
          *(uint16_t *)(__s + 8) = (peVar4->field_2).field_1.timeout;
        }
      }
      convert_to_ezb_general_cmd_ctrl
                ((ezb_zcl_cmd_ctrl_t *)auStack_44,(esp_zb_zcl_general_cmd_header_t *)cmd_req);
      req.cmd_ctrl.cnf_ctx.user_ctx._0_2_ = uVar2;
      req.payload._0_4_ = __ptr;
      iVar6 = ezb_zcl_config_report_cmd_req(auStack_44);
      uVar5 = 0xff;
      if (iVar6 == 0) {
        uVar5 = zcl_get_current_tsn();
      }
      free(__ptr);
      return uVar5;
    }
  }
  return 0xff;
}

