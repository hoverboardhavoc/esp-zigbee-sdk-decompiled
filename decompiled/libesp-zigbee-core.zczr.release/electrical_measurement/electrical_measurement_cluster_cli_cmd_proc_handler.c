/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> electrical_measurement.o -> electrical_measurement_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010306) */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t electrical_measurement_cluster_cli_cmd_proc_handler(void *arg)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint16_t uStack_6a;
  undefined1 auStack_68 [2];
  uint16_t offset;
  ezb_zcl_electrical_measurement_get_prof_info_rsp_message_t message;
  undefined1 auStack_48 [4];
  zcl_packet_t rsp;
  
  iVar1 = 1;
  memset(auStack_48,0,0x28);
  if (arg == (void *)0x0) goto _L0;
  iVar1 = 1;
  if (((*(byte *)((int)arg + 0x1a) & 8) == 0) ||
     (iVar1 = zcl_packet_init(auStack_48,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar1 != 0))
  goto _L0;
  if (*(char *)((int)arg + 0x20) == '\0') {
    memset(auStack_68,0,0x18);
    uStack_6a = 0;
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_6a,(uint8_t *)&message.in);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_6a,(uint8_t *)((int)&message.in.header + 1));
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_6a,(uint8_t *)((int)&message.in.header + 2));
    uVar3 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    uVar2 = (uint)uStack_6a;
    uVar4 = 0x80;
    if (uVar2 <= uVar3) {
      iVar1 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      uVar3 = iVar1 - uVar2 >> 1 & 0xffff;
      if (uVar3 != 0) {
        message.in.payload._0_4_ = calloc(uVar3,2);
        uVar4 = 0x89;
        if ((void *)message.in.payload._0_4_ == (void *)0x0) goto _L0;
        uVar4 = 0;
        do {
          iVar1 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uVar2,2,
                                  uVar4 * 2 + message.in.payload._0_4_);
          uVar5 = 0xffff;
          if (iVar1 != 0) {
            uVar5 = uVar2 + iVar1 & 0xffff;
          }
          uVar4 = uVar4 + 1;
          uStack_6a = (uint16_t)uVar5;
          uVar2 = uVar5;
        } while ((uVar4 & 0xffff) < uVar3);
      }
      uVar4 = zcl_packet_to_message(auStack_68,arg);
      if (uVar4 == 0) {
        message.in.payload.list_of_attributes._0_1_ = 0xfe;
        message._4_4_ = arg;
        zcl_core_action_schedule(0x40,auStack_68);
        if ((byte)message.in.payload.list_of_attributes != 0xfe) {
          uVar4 = (uint)(byte)message.in.payload.list_of_attributes;
        }
      }
    }
_L0:
    if (message.in.payload._0_4_ != 0) {
      mm_free();
    }
  }
  else if (*(char *)((int)arg + 0x20) == '\x01') {
    memset(auStack_68,0,0x20);
    iVar1 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,4,&message.in);
    if (iVar1 == 0) {
      iVar1 = 0xffff;
    }
    uStack_6a = (uint16_t)iVar1;
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_6a,&message.in.payload.prof_count);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_6a,&message.in.payload.prof_interval_period);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_6a,&message.in.payload.max_num_of_intervals);
    uVar2 = (uint)uStack_6a;
    iVar1 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uVar2,2,
                            &message.in.payload.list_of_attributes);
    if (iVar1 == 0) {
      uVar2 = 0xffff;
    }
    else {
      uVar2 = uVar2 + iVar1 & 0xffff;
    }
    uVar4 = 0x80;
    uStack_6a = (ushort)uVar2;
    uVar3 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    if (uVar2 <= uVar3) {
      if (((uint)message.in.payload._0_4_ >> 0x10 & 0xff) != 0) {
        uVar4 = 0x89;
        iVar1 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        uVar3 = iVar1 - uVar2 & 0xffff;
        message._20_4_ = calloc(uVar3,1);
        if ((void *)message._20_4_ == (void *)0x0) goto _L0;
        iVar1 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uVar2,uVar3,message._20_4_);
        if ((iVar1 == 0) && (uVar3 != 0)) {
          uStack_6a = 0xffff;
        }
        else {
          uStack_6a = (ushort)uVar2 + (short)iVar1;
        }
      }
      uVar4 = zcl_packet_to_message(auStack_68,arg);
      if (uVar4 == 0) {
        message._4_4_ = arg;
        zcl_core_action_schedule(0x41,auStack_68);
      }
    }
_L0:
    if (message._20_4_ != 0) {
      mm_free();
    }
  }
  else {
    uVar4 = 0x81;
  }
  iVar1 = zcl_packet_setup_default_response(auStack_48,arg,uVar4);
  if (iVar1 == 0) {
    zcl_packet_send(auStack_48,0);
  }
  else {
    zcl_packet_free(auStack_48);
  }
_L0:
  return (ezb_zcl_status_t)iVar1;
}

