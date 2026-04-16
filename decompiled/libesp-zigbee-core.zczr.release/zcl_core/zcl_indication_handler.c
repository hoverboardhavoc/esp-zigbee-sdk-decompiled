/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_core.o -> zcl_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: packet */
/* WARNING: Unknown calling convention */

zcl_status_t zcl_indication_handler(af_data_ind_t *arg)

{
  bool bVar1;
  anon_struct_1_1_6971b95b_for_out *__s;
  zcl_status_t zVar2;
  int iVar3;
  uint uVar4;
  size_t __size;
  anon_struct_1_1_6971b95b_for_out *paStack_50;
  zcl_manuf_spec_cmd_message_t message;
  zcl_packet_t packet;
  
  __s = &message.out;
  memset(__s,0,0x28);
  if (arg != (af_data_ind_t *)0x0) goto _L0;
  do {
    do {
      __assert_func(0,0,0,0);
_L0:
      iVar3 = zcl_packet_init_with_msg(__s,arg);
      if (iVar3 != 0) goto _L0;
      iVar3 = core_globals_get();
      arg = (af_data_ind_t *)0x1000;
      if (*(int *)(iVar3 + 0xd7c) == 0) goto _L0;
      iVar3 = core_globals_get();
    } while (*(int *)(iVar3 + 0xd7c) == 0);
    paStack_50 = __s;
    arg = (af_data_ind_t *)zmsg_get_length(packet._32_4_);
    message.info._0_2_ = SUB42(arg,0);
    message._4_4_ = calloc(1,(size_t)arg);
    if (((void *)message._4_4_ == (void *)0x0) && (arg != (af_data_ind_t *)0x0)) {
      iVar3 = 1;
      goto _L0;
    }
    uVar4 = zmsg_read_bytes(packet._32_4_,0,arg,message._4_4_);
    if (uVar4 == 0) {
      bVar1 = arg != (af_data_ind_t *)0x0;
      arg = (af_data_ind_t *)-(uint)bVar1;
      uVar4 = (uint)bVar1 * -0x10000 >> 0x10;
    }
  } while ((ushort)message.info._0_2_ != uVar4);
  iVar3 = core_globals_get();
  iVar3 = (**(code **)(iVar3 + 0xd7c))(&paStack_50,*(code **)(iVar3 + 0xd7c));
_L0:
  if (message._4_4_ != 0) {
    mm_free();
  }
  if (iVar3 != 0) {
    return '\0';
  }
_L0:
  uVar4 = zcl_packet_is_acceptable(__s);
  if (uVar4 != 0) goto _L0;
  iVar3 = zcl_packet_is_general(__s);
  if (iVar3 == 0) {
    iVar3 = zcl_packet_is_manuf_spec(__s);
    if (iVar3 == 0) {
      uVar4 = zcl_cluster_cmd_handler(__s);
    }
    else {
      memset(&paStack_50,0,0x18);
      uVar4 = zcl_packet_to_message(&paStack_50,__s);
      if (uVar4 == 0) {
        message._4_4_ = __s;
        __size = zcl_packet_payload_get_length(packet._32_4_);
        message.in.header._0_2_ = (undefined2)__size;
        message.in._4_4_ = calloc(1,__size);
        if ((void *)message.in._4_4_ == (void *)0x0) {
          uVar4 = 0x89;
          if (__size != 0) goto _L0;
_L0:
          message.in.payload_size = 0;
          message.in._6_2_ = 0;
        }
        else if (__size == 0) goto _L0;
        zmsg_read_bytes(packet._32_4_,0,message.in._4_4_);
        message.in.payload._0_1_ = 0xfe;
        zcl_core_action_schedule(9,&paStack_50);
        uVar4 = (uint)(byte)message.in.payload;
        if (uVar4 == 0xfe) {
          uVar4 = 0;
        }
        zcl_packet_send_default_response(__s,uVar4);
      }
_L0:
      if (message.in._4_4_ != 0) {
        mm_free();
      }
    }
  }
  else {
    uVar4 = zcl_general_cmd_handler(__s);
  }
  if (uVar4 == 0) {
    return '\0';
  }
_L0:
  if (uVar4 == 0xfe) {
_L0:
    zVar2 = 0xfe;
  }
  else {
    zVar2 = zcl_packet_send_default_response(__s,uVar4);
  }
  return zVar2;
}

