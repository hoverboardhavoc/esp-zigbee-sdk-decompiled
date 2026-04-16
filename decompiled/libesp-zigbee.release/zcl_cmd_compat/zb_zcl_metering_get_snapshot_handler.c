/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_metering_get_snapshot_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_metering_get_snapshot_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  esp_zb_uint48_t *peVar1;
  ezb_zcl_status_t eVar2;
  esp_err_t err;
  uint32_t *puVar3;
  undefined4 *puVar4;
  uint64_t *puVar5;
  uint uVar6;
  undefined2 uStack_64;
  undefined2 uStack_62;
  esp_zb_zcl_metering_get_snapshot_message_t app_message;
  
  memset(&app_message.latest_end_time,0,0x38);
  uStack_62 = *(undefined2 *)((int)arg + 2);
                    /* WARNING: Load size is inaccurate */
  uStack_64 = *arg;
  app_message.info = *(esp_zb_device_cb_common_info_t *)((int)arg + 0xc);
  app_message.earliest_start_time = *(uint32_t *)((int)arg + 0x10);
  app_message.latest_end_time._0_1_ = *(undefined1 *)((int)arg + 0x14);
  app_message._12_4_ = *(undefined4 *)((int)arg + 0x18);
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_METERING_GET_SNAPSHOT_CB_ID,&uStack_64);
    eVar2 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x1c) = eVar2;
  }
  if (*(char *)((int)arg + 0x1c) != '\0') {
    if (*(void **)((int)arg + 0x20) == (void *)0x0) {
      return;
    }
    free(*(void **)((int)arg + 0x20));
    return;
  }
  puVar3 = (uint32_t *)calloc(1,0x40);
  *(uint32_t **)((int)arg + 0x20) = puVar3;
  if (puVar3 == (uint32_t *)0x0) goto _L0;
  *(undefined1 *)((int)puVar3 + 10) = 1;
  *puVar3 = app_message.snapshot_cause;
  *(undefined1 *)((int)puVar3 + 9) = 0;
  puVar3[1] = app_message.resp_info_offered.snapshot_id;
  *(undefined1 *)(puVar3 + 2) = (undefined1)app_message.resp_info_offered.snapshot_time;
  *(byte *)(puVar3 + 4) = (byte)app_message.resp_info_offered.snapshot_cause;
  puVar3[3] = (uint)app_message.resp_info_offered.total_snapshots_found << 0x18 |
              app_message.resp_info_offered.snapshot_time >> 8;
  puVar4 = (undefined4 *)calloc(1,0xc);
  if (puVar4 == (undefined4 *)0x0) goto _L0;
  *puVar4 = puVar3;
  if ((byte)app_message.resp_info_offered.snapshot_cause == 4) {
_L0:
    array_copy_u48_to_u64
              ((uint64_t *)(puVar3 + 6),
               (esp_zb_uint48_t *)((int)&app_message.resp_info_offered.snapshot_cause + 1),1);
    uVar6 = app_message.resp_info_offered.snapshot_sub_payload._2_4_ & 0xff;
    *(undefined1 *)(puVar3 + 8) =
         app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
         current_summation_delivered.low._2_1_;
    if ((uVar6 == 0) ||
       (peVar1 = (esp_zb_uint48_t *)
                 ((uint)app_message.resp_info_offered.snapshot_sub_payload.tou_delivered_no_billing.
                        number_of_tiers_in_use << 0x18 |
                 (uint)app_message.resp_info_offered.snapshot_sub_payload._2_4_ >> 8),
       peVar1 == (esp_zb_uint48_t *)0x0)) goto _L0;
    puVar5 = (uint64_t *)calloc(uVar6,8);
    if (puVar5 == (uint64_t *)0x0) goto _L0;
    array_copy_u48_to_u64(puVar5,peVar1,uVar6);
    puVar3[9] = (uint32_t)puVar5;
_L0:
    puVar4[1] = puVar5;
  }
  else {
    if ((byte)app_message.resp_info_offered.snapshot_cause < 5) {
      puVar5 = (uint64_t *)(puVar3 + 6);
      if ((byte)app_message.resp_info_offered.snapshot_cause == 2) {
        array_copy_u48_to_u64
                  (puVar5,(esp_zb_uint48_t *)
                          ((int)&app_message.resp_info_offered.snapshot_cause + 1),1);
        puVar3[0xb] = app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                      projected_bill_delivered;
        uVar6 = (uint)(byte)app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                            projected_bill_time_stamp_delivered._1_1_;
        puVar3[8] = app_message.resp_info_offered.snapshot_sub_payload._2_4_;
        puVar3[9] = CONCAT22(app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                             bill_to_date_delivered._2_2_,
                             CONCAT11(app_message.resp_info_offered.snapshot_sub_payload.
                                      tou_delivered.bill_to_date_delivered._1_1_,
                                      app_message.resp_info_offered.snapshot_sub_payload.
                                      tou_delivered_no_billing.number_of_tiers_in_use));
        puVar3[10] = CONCAT22(app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                              bill_to_date_time_stamp_delivered._2_2_,
                              app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                              bill_to_date_time_stamp_delivered._0_2_);
        *(undefined2 *)(puVar3 + 0xc) =
             app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
             projected_bill_time_stamp_delivered._0_2_;
        if ((uVar6 != 0) && (app_message.resp_info_offered.snapshot_sub_payload._20_4_ != 0)) {
          puVar5 = (uint64_t *)calloc(uVar6,8);
          if (puVar5 == (uint64_t *)0x0) goto _L0;
          array_copy_u48_to_u64
                    (puVar5,(esp_zb_uint48_t *)
                            app_message.resp_info_offered.snapshot_sub_payload._20_4_,uVar6);
          puVar3[0xd] = (uint32_t)puVar5;
          puVar4[1] = puVar5;
        }
      }
      else {
        if ((byte)app_message.resp_info_offered.snapshot_cause != 3) {
          array_copy_u48_to_u64
                    (puVar5,(esp_zb_uint48_t *)
                            ((int)&app_message.resp_info_offered.snapshot_cause + 1),1);
          uVar6 = (uint)(byte)app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                              projected_bill_time_stamp_delivered._1_1_;
          puVar3[0xb] = app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                        projected_bill_delivered;
          puVar3[8] = app_message.resp_info_offered.snapshot_sub_payload._2_4_;
          puVar3[9] = CONCAT22(app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                               bill_to_date_delivered._2_2_,
                               CONCAT11(app_message.resp_info_offered.snapshot_sub_payload.
                                        tou_delivered.bill_to_date_delivered._1_1_,
                                        app_message.resp_info_offered.snapshot_sub_payload.
                                        tou_delivered_no_billing.number_of_tiers_in_use));
          puVar3[10] = CONCAT22(app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                                bill_to_date_time_stamp_delivered._2_2_,
                                app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                                bill_to_date_time_stamp_delivered._0_2_);
          *(undefined2 *)(puVar3 + 0xc) =
               app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
               projected_bill_time_stamp_delivered._0_2_;
          if ((uVar6 == 0) || (app_message.resp_info_offered.snapshot_sub_payload._20_4_ == 0))
          goto _L0;
          puVar5 = (uint64_t *)calloc(uVar6,8);
          if (puVar5 == (uint64_t *)0x0) goto _L0;
          array_copy_u48_to_u64
                    (puVar5,(esp_zb_uint48_t *)
                            app_message.resp_info_offered.snapshot_sub_payload._20_4_,uVar6);
          puVar3[0xd] = (uint32_t)puVar5;
          goto _L0;
        }
        array_copy_u48_to_u64
                  (puVar5,(esp_zb_uint48_t *)
                          ((int)&app_message.resp_info_offered.snapshot_cause + 1),1);
        puVar3[0xb] = app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                      projected_bill_delivered;
        uVar6 = (uint)(byte)app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                            projected_bill_time_stamp_delivered._1_1_;
        puVar3[8] = app_message.resp_info_offered.snapshot_sub_payload._2_4_;
        puVar3[9] = CONCAT22(app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                             bill_to_date_delivered._2_2_,
                             CONCAT11(app_message.resp_info_offered.snapshot_sub_payload.
                                      tou_delivered.bill_to_date_delivered._1_1_,
                                      app_message.resp_info_offered.snapshot_sub_payload.
                                      tou_delivered_no_billing.number_of_tiers_in_use));
        puVar3[10] = CONCAT22(app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                              bill_to_date_time_stamp_delivered._2_2_,
                              app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                              bill_to_date_time_stamp_delivered._0_2_);
        *(undefined2 *)(puVar3 + 0xc) =
             app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
             projected_bill_time_stamp_delivered._0_2_;
        if ((uVar6 != 0) && (app_message.resp_info_offered.snapshot_sub_payload._20_4_ != 0)) {
          puVar5 = (uint64_t *)calloc(uVar6,8);
          if (puVar5 == (uint64_t *)0x0) goto _L0;
          array_copy_u48_to_u64
                    (puVar5,(esp_zb_uint48_t *)
                            app_message.resp_info_offered.snapshot_sub_payload._20_4_,uVar6);
          puVar3[0xd] = (uint32_t)puVar5;
          puVar4[1] = puVar5;
        }
      }
      uVar6 = (uint)(byte)app_message.resp_info_offered.snapshot_sub_payload._24_1_;
      *(undefined1 *)(puVar3 + 0xe) = app_message.resp_info_offered.snapshot_sub_payload._24_1_;
      if ((uVar6 == 0) ||
         (peVar1 = (esp_zb_uint48_t *)
                   (app_message.resp_info_offered.snapshot_sub_payload._26_4_ << 8 |
                   (uint)(byte)app_message.resp_info_offered.snapshot_sub_payload._25_1_),
         peVar1 == (esp_zb_uint48_t *)0x0)) goto _L0;
      puVar5 = (uint64_t *)calloc(uVar6,8);
      if (puVar5 == (uint64_t *)0x0) {
_L0:
        esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
        return;
      }
      array_copy_u48_to_u64(puVar5,peVar1,uVar6);
      puVar3[0xf] = (uint32_t)puVar5;
    }
    else {
      if ((byte)app_message.resp_info_offered.snapshot_cause == 6) {
        array_copy_u48_to_u64
                  ((uint64_t *)(puVar3 + 6),
                   (esp_zb_uint48_t *)((int)&app_message.resp_info_offered.snapshot_cause + 1),1);
        uVar6 = app_message.resp_info_offered.snapshot_sub_payload._2_4_ & 0xff;
        *(undefined1 *)(puVar3 + 8) =
             app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
             current_summation_delivered.low._2_1_;
        if ((uVar6 != 0) &&
           (peVar1 = (esp_zb_uint48_t *)
                     ((uint)app_message.resp_info_offered.snapshot_sub_payload.
                            tou_delivered_no_billing.number_of_tiers_in_use << 0x18 |
                     (uint)app_message.resp_info_offered.snapshot_sub_payload._2_4_ >> 8),
           peVar1 != (esp_zb_uint48_t *)0x0)) {
          puVar5 = (uint64_t *)calloc(uVar6,8);
          if (puVar5 == (uint64_t *)0x0) goto _L0;
          array_copy_u48_to_u64(puVar5,peVar1,uVar6);
          puVar3[9] = (uint32_t)puVar5;
          puVar4[1] = puVar5;
        }
      }
      else {
        if ((byte)app_message.resp_info_offered.snapshot_cause != 7) {
          if ((byte)app_message.resp_info_offered.snapshot_cause != 5) goto _L0;
          goto _L0;
        }
        array_copy_u48_to_u64
                  ((uint64_t *)(puVar3 + 6),
                   (esp_zb_uint48_t *)((int)&app_message.resp_info_offered.snapshot_cause + 1),1);
        uVar6 = app_message.resp_info_offered.snapshot_sub_payload._2_4_ & 0xff;
        *(undefined1 *)(puVar3 + 8) =
             app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
             current_summation_delivered.low._2_1_;
        if ((uVar6 != 0) &&
           (peVar1 = (esp_zb_uint48_t *)
                     ((uint)app_message.resp_info_offered.snapshot_sub_payload.
                            tou_delivered_no_billing.number_of_tiers_in_use << 0x18 |
                     (uint)app_message.resp_info_offered.snapshot_sub_payload._2_4_ >> 8),
           peVar1 != (esp_zb_uint48_t *)0x0)) {
          puVar5 = (uint64_t *)calloc(uVar6,8);
          if (puVar5 == (uint64_t *)0x0) goto _L0;
          array_copy_u48_to_u64(puVar5,peVar1,uVar6);
          puVar3[9] = (uint32_t)puVar5;
          puVar4[1] = puVar5;
        }
      }
      uVar6 = (uint)(byte)app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                          bill_to_date_delivered._1_1_;
      *(undefined1 *)(puVar3 + 10) =
           app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.bill_to_date_delivered.
           _1_1_;
      if ((uVar6 == 0) ||
         ((esp_zb_uint48_t *)
          CONCAT22(app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                   bill_to_date_time_stamp_delivered._0_2_,
                   app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                   bill_to_date_delivered._2_2_) == (esp_zb_uint48_t *)0x0)) goto _L0;
      puVar5 = (uint64_t *)calloc(uVar6,8);
      if (puVar5 == (uint64_t *)0x0) goto _L0;
      array_copy_u48_to_u64
                (puVar5,(esp_zb_uint48_t *)
                        CONCAT22(app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                                 bill_to_date_time_stamp_delivered._0_2_,
                                 app_message.resp_info_offered.snapshot_sub_payload.tou_delivered.
                                 bill_to_date_delivered._2_2_),uVar6);
      puVar3[0xb] = (uint32_t)puVar5;
    }
    puVar4[2] = puVar5;
  }
_L0:
  *(code **)((int)arg + 0x24) = free_metering_snapshot_mem;
  *(undefined4 **)((int)arg + 0x28) = puVar4;
  return;
}

